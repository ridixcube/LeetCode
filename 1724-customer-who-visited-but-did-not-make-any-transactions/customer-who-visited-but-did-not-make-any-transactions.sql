select customer_id , Count(visit_id) as count_no_trans from Visits 
where visit_id not in (select visit_id from Transactions) 
Group by customer_id;