-- CREATE TABLE Employee (
--     person_name VARCHAR(100) PRIMARY KEY,  -- Assuming person_name is unique
--     street VARCHAR(100),
--     city VARCHAR(100)
-- );
-- CREATE TABLE Company (
--     company_name VARCHAR(100) PRIMARY KEY,  -- Assuming company_name is unique
--     city VARCHAR(100)
-- );
-- CREATE TABLE Manages (
--     person_name VARCHAR(100),   -- Foreign key referencing Employee
--     manager_name VARCHAR(100),  -- Foreign key referencing Employee (self-referencing)
--     PRIMARY KEY (person_name, manager_name),
--     FOREIGN KEY (person_name) REFERENCES Employee(person_name),
--     FOREIGN KEY (manager_name) REFERENCES Employee(person_name)
-- );
-- CREATE TABLE Works (
--     person_name VARCHAR(100),   -- Foreign key referencing Employee
--     company_name VARCHAR(100),  -- Foreign key referencing Company
--     salary DECIMAL(10, 2),      -- Salary with two decimal places
--     PRIMARY KEY(person_name, company_name),  -- Composite key
--     FOREIGN KEY (person_name) REFERENCES Employee(person_name),
--     FOREIGN KEY (company_name) REFERENCES Company(company_name)
-- );

-- INSERT INTO Employee (person_name, street, city)
-- VALUES
-- ('John Doe', '123 Elm St', 'Hamirpur'),
-- ('Jane Smith', '456 Oak St', 'Delhi'),
-- ('Prateek Sharma', '789 Pine St', 'Hamirpur');

-- INSERT INTO Company (company_name, city)
-- VALUES
-- ('First Bank Corporation', 'Hamirpur'),
-- ('NIT, Hamirpur', 'Hamirpur');

-- INSERT INTO Works (person_name, company_name, salary)
-- VALUES
-- ('John Doe', 'First Bank Corporation', 15000),
-- ('Jane Smith', 'NIT, Hamirpur', 12000),
-- ('Prateek Sharma', 'NIT, Hamirpur', 9500);

-- INSERT INTO Manages (person_name, manager_name)
-- VALUES
-- ('John Doe', 'Jane Smith'),
-- ('Prateek Sharma', 'John Doe');


-- -- 1. Find the names and cities of residence of all employees who work for First Bank Corporation:

--  SELECT e.person_name, e.city
-- FROM Employee e
-- JOIN Works w ON e.person_name = w.person_name
-- WHERE w.company_name = 'First Bank Corporation';


-- -- 2. Find the name, street number, and cities of residence of all employees who work for "NIT, Hamirpur" and earn more than Rs10,000:

-- SELECT e.person_name, e.street, e.city
-- FROM Employee e
-- JOIN Works w ON e.person_name = w.person_name
-- WHERE w.company_name = 'NIT, Hamirpur'
--   AND w.salary > 10000;

