# Write your MySQL query statement below
select A.Id From Weather A, Weather B
where DATEDIFF(A.RecordDate, B.RecordDate)=1 and A.Temperature > B.Temperature;

# NOTICE: datadiff(A,B)=1, means A-B=1, passed 287ms
