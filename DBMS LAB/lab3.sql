create table employee(
empId INT primary key,
person_name varchar(100),
street varchar(100),
city varchar(20)
);

create table company(
	companyId int primary key,
    company_name varchar(100),
    city varchar(20)
    );

create table works(
empId Int,
companyId int,
salary INT,
foreign key (empId) references employee(empId),
foreign key (companyId) references company(companyId)
);

create table manages(
empId int,
manager_id int,
primary key (empId, manager_id),
foreign key (empId) references employee(empId),
foreign key (manager_id) references employee(empId)
);

DELIMITER $$

CREATE PROCEDURE InsertIntoManages2(
    IN employee_id INT,
    IN manager_id INT
)
BEGIN
    -- Check if both the employee and the manager work in the same company
	IF employee_id = manager_id THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Employee cannot be their own manager';
    ELSE
		IF EXISTS (
        SELECT 1
        FROM works AS w1
        JOIN works AS w2
        ON w1.companyId = w2.companyId
        WHERE w1.empId = employee_id AND w2.empId = manager_id
		) THEN
        -- If they belong to the same company, insert the record
        INSERT INTO manages (empId, manager_id)
        VALUES (employee_id, manager_id);
		ELSE
        -- If not, signal an error
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Employee and Manager do not belong to the same company';
        end if;
    END IF;
    
END $$

DELIMITER ;


insert into employee (empId, person_name, street, city) values
(1, 'Rohan', 'Anu', 'Hamirpur'),
(2, 'Mohan', 'Chandni Chowk', 'Delhi'),
(3, 'Sohan', 'Nerchowk', 'Mandi'),
(4, 'Mohit', 'Busstand', 'UNA');

insert into company (companyId, company_name, city) values
(1, 'Triology', 'Delhi'),
(2, 'Google', 'Hyderabaad'),
(3, 'Microsoft', 'Pune'),
(4, 'Netflix', 'New York');

insert into works (empId, companyId, salary) values
(1, 1, 200000),
(3, 2, 320000),
(2, 3, 400000),
(4, 4, 500000),
(4, 2, 20000);

call insertIntoManages2(4,3);

DELIMITER $$
create procedure insertCompany(
In name varchar(100),
In city varchar(20)
)
BEGIN
	DECLARE MAX_ID INT;
    select 
    SELECT ifnull(MAX(COMPANYID), 0) INTO MAX_ID FROM COMPANY;
    
    INSERT INTO COMPANY VALUES
    (MAX_ID+1,  NAME, CITY);
    
END $$
DELIMITER ;

CALL INSERTCOMPANY('TRILLICORN', 'INDIA');