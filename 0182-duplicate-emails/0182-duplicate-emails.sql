# Write your MySQL query statement below
SELECT email 
FROM person 
Group by email
having count(DISTINCT id)>1