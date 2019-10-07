# passed 265ms
# Write your MySQL query statement below

select A.Name as Employee From
    Employee as A Join Employee as B
    on A.ManagerId = B.Id
    and A.Salary > B.Salary;
