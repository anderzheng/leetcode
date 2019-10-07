# Write your MySQL query statement below
delete A.* from Person A, Person B 
where A.Email = B.Email and A.Id > B.Id;

# passed: 712ms
