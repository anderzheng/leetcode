/* using 2 stacks, passed: 32ms */

#define     MAX_SIZE       1024
typedef struct {
    int  buff[MAX_SIZE];
    int  min[MAX_SIZE];
    //int head;
    int tail;
    //int minVal;
    //int minIdx;
    
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *ptr = NULL;
    
    ptr = (MinStack*)malloc(sizeof(MinStack));
    if (NULL == ptr)
    {
        return NULL;
    }
    memset(ptr, 0, sizeof(MinStack));
    return ptr;
    
}

void minStackPush(MinStack* obj, int x) {
    if(NULL == obj)
        return;
    
    if (obj->tail <MAX_SIZE)
    {
        obj->buff[obj->tail] = x;
        if (obj->tail == 0)
            obj->min[obj->tail] = x;
        else if (obj->min[obj->tail-1] > x)
        {
            obj->min[obj->tail] = x;
        }
        else
            obj->min[obj->tail] = obj->min[obj->tail -1];   // don't forget this.
        obj->tail ++;
    }
    
}

void minStackPop(MinStack* obj) {
    int i=0;
    if(NULL == obj || obj->tail <=0)
        return;
    
    if (obj->tail > 0)
    {
        obj->tail --;
        obj->buff[obj->tail] = 0;
        obj->min[obj->tail] = 0;
    }  
}

int minStackTop(MinStack* obj) {
    if(NULL == obj || obj->tail<=0)
        return -1;
    
    return obj->buff[obj->tail-1];
}

int minStackGetMin(MinStack* obj) {
    if(NULL == obj || obj->tail <=0)
        return -1;
  
    return obj->min[obj->tail -1];
}

void minStackFree(MinStack* obj) {
    if(NULL == obj)
        return;
    
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
//--------------------------------------------------------------------------

/* passed: 36ms */

#define     MAX_SIZE       1024
typedef struct {
    int  buff[MAX_SIZE];
    //int head;
    int tail;
    int minVal;
    //int minIdx;
    
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *ptr = NULL;
    
    ptr = (MinStack*)malloc(sizeof(MinStack));
    if (NULL == ptr)
    {
        return NULL;
    }
    memset(ptr, 0, sizeof(MinStack));
    return ptr;
    
}

void minStackPush(MinStack* obj, int x) {
    if(NULL == obj)
        return;
    
    if (obj->tail <MAX_SIZE)
    {
        obj->buff[obj->tail++] = x;
        if (obj->tail == 1)
            obj->minVal = x;
        else if (obj->minVal > x)
        {
            obj->minVal = x;
            //obj->minIdx = obj->tail;
        }
    }
    
}

void minStackPop(MinStack* obj) {
    int i=0;
    if(NULL == obj || obj->tail <=0)
        return;
    
    if (obj->tail > 0)
    {
        obj->tail --;
        //if (obj->tail == obj->minIdx)
        if (obj->minVal == obj->buff[obj->tail])
        {
            /* need to find the new minimum element */
            //obj->minIdx = 0;
            obj->minVal = obj->buff[0];

            for(i=1;i<obj->tail; i++)
            {
                if(obj->minVal > obj->buff[i])
                {
                    //obj->minIdx = i;
                    obj->minVal = obj->buff[i];
                }
            }
        }
        obj->buff[obj->tail] = 0;
    }  
}

int minStackTop(MinStack* obj) {
    if(NULL == obj || obj->tail<=0)
        return -1;
    
    return obj->buff[obj->tail-1];
}

int minStackGetMin(MinStack* obj) {
    if(NULL == obj || obj->tail <=0)
        return -1;
  
    return obj->minVal;
}

void minStackFree(MinStack* obj) {
    if(NULL == obj)
        return;
    
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
