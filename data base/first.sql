with maxcountry (country , costumerCount) as 
(select countrt , max (*) as customerCountfrom customers 
group by country) 