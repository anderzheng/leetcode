# using left join, passed 163ms
# Write your MySQL query statement below
select FirstName,LastName,City,State from Person left join Address on Person.PersonId = Address.PersonId;
