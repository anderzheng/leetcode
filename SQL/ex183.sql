# passed 185ms
# Write your MySQL query statement below

select A.Name as Customers 
    from Customers A left join Orders B
    on A.Id = B.CustomerId
    where B.Id is NULL;   # notice: "is null", cannot use "=null"
