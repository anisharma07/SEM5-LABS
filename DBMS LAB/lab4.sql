-- CREATE TABLE Person (
--     driver_id INT PRIMARY KEY,  -- Assuming the driver_id is unique for each person
--     name VARCHAR(100),
--     address VARCHAR(255)
-- );


-- CREATE TABLE Car (
--     license VARCHAR(50) PRIMARY KEY,  -- Assuming license is unique for each car
--     model VARCHAR(100),
--     year INT
-- );

-- CREATE TABLE Accident (
--     report_number INT PRIMARY KEY,  -- Unique report number for each accident
--     date DATE,                      -- Date of the accident
--     location VARCHAR(255)
-- );

-- CREATE TABLE Owns (
--     driver_id INT,     -- Foreign key referencing the Person table
--     license VARCHAR(50),  -- Foreign key referencing the Car table
--     PRIMARY KEY(driver_id, license),
--     FOREIGN KEY (driver_id) REFERENCES Person(driver_id),
--     FOREIGN KEY (license) REFERENCES Car(license)
-- );

-- CREATE TABLE Participated (
--     driver_id INT,        -- Foreign key referencing the Person table
--     car VARCHAR(50),      -- Foreign key referencing the Car table
--     report_number INT,    -- Foreign key referencing the Accident table
--     damage_amount DECIMAL(10, 2),  -- The amount of damage caused in the accident
--     PRIMARY KEY (driver_id, car, report_number),
--     FOREIGN KEY (driver_id) REFERENCES Person(driver_id),
--     FOREIGN KEY (car) REFERENCES Car(license),
--     FOREIGN KEY (report_number) REFERENCES Accident(report_number)
-- );

-- INSERT INTO Person (driver_id, name, address)
-- VALUES
-- (1, 'Prateek', '123 Main St'),
-- (2, 'Aman', '456 Oak St'),
-- (3, 'Neha', '789 Pine St');

-- INSERT INTO Car (license, model, year)
-- VALUES
-- ('KA01AB1234', 'SANTRO', 2005),
-- ('DL05XY6789', 'SWIFT', 2010),
-- ('MH12GH4321', 'HONDA CITY', 2012);

-- INSERT INTO Accident (report_number, date, location)
-- VALUES
-- (1001, '2007-05-12', 'Downtown'),
-- (1002, '2007-11-23', 'Highway'),
-- (1003, '2024-09-23', 'City Center');

-- INSERT INTO Owns (driver_id, license)
-- VALUES
-- (1, 'KA01AB1234'),  -- Prateek owns SANTRO
-- (2, 'DL05XY6789'),  -- Aman owns SWIFT
-- (3, 'MH12GH4321');  -- Neha owns HONDA CITY

-- INSERT INTO Participated (driver_id, car, report_number, damage_amount)
-- VALUES
-- (1, 'KA01AB1234', 1001, 5000.00),  
-- (2, 'DL05XY6789', 1002, 7500.00), 
-- (3, 'MH12GH4321', 1003, 12000.00); 


-- -- 1. Find the number of people who owned cars that were involved in accidents in 2007:
-- SELECT COUNT(DISTINCT p.driver_id) AS number_of_people
-- FROM Person p
-- JOIN Owns o ON p.driver_id = o.driver_id
-- JOIN Participated pa ON o.license = pa.car
-- JOIN Accident a ON pa.report_number = a.report_number
-- WHERE YEAR(a.date) = 2007;

-- -- 2. Add a new accident to the database:
-- INSERT INTO Accident (report_number, date, location)
-- VALUES (1004, '2024-10-01', 'Market Square');

-- -- 3. Delete the SANTRO belonging to "Prateek":
--  DELETE FROM Owns
--     WHERE license IN (
--       SELECT license FROM (
--            SELECT o.license
--              FROM Owns o
--             JOIN Person p ON o.driver_id = p.driver_id
--             JOIN Car c ON o.license = c.license
--            WHERE p.name = 'Prateek' AND c.model = 'SANTRO'
--         ) AS subquery
--     );
    
    