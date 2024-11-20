-- CREATE TABLE Teachers (
--     teacher_id INT PRIMARY KEY,
--     teacher_name VARCHAR(100)
-- );

-- CREATE TABLE Classes (
--     class_id INT PRIMARY KEY,
--     class_name VARCHAR(100),
--     teacher_id INT,
--     FOREIGN KEY (teacher_id) REFERENCES Teachers(teacher_id)
-- );

-- CREATE TABLE Students (
--     student_id INT PRIMARY KEY,
--     student_name VARCHAR(100)
-- );

-- CREATE TABLE Enrollments (
--     enrollment_id INT PRIMARY KEY,
--     class_id INT,
--     student_id INT,
--     FOREIGN KEY (class_id) REFERENCES Classes(class_id),
--     FOREIGN KEY (student_id) REFERENCES Students(student_id)
-- );

-- CREATE TABLE Grades (
--     student_id INT,
--     class_id INT,
--     grade CHAR(2),
--     PRIMARY KEY (student_id, class_id),
--     FOREIGN KEY (student_id) REFERENCES Students(student_id),
--     FOREIGN KEY (class_id) REFERENCES Classes(class_id)
-- );
-- CREATE TABLE ClassSchedule (
--     schedule_id INT PRIMARY KEY,
--     class_id INT,
--     day ENUM('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'),
--     start_time TIME,
--     end_time TIME,
--     FOREIGN KEY (class_id) REFERENCES Classes(class_id)
-- );

-- INSERT INTO Teachers (teacher_id, teacher_name) VALUES
-- (1, 'John Smith'),
-- (2, 'Jane Doe'),
-- (3, 'Emily Johnson'),
-- (4, 'Michael Brown');


-- INSERT INTO Classes (class_id, class_name, teacher_id) VALUES
-- (1, 'ADDA', 1),
-- (2, 'DBMS', 2),
-- (3, 'Graphics', 3),
-- (4, 'Disaster', 4);

-- INSERT INTO Students (student_id, student_name) VALUES
-- (1, 'Anirudh'),
-- (2, 'Anshul'),
-- (3, 'Pushp'),
-- (4, 'Rohan');

-- INSERT INTO Enrollments (enrollment_id, class_id, student_id) VALUES
-- (1, 1, 1),  -- Alice Green is enrolled in Mathematics
-- (2, 2, 2),  -- Bob White is enrolled in Science
-- (3, 3, 3),  -- Charlie Black is enrolled in History
-- (4, 4, 4),  -- Diana Blue is enrolled in English
-- (5, 1, 2),  -- Bob White is also enrolled in Mathematics
-- (6, 3, 4);  -- Diana Blue is also enrolled in History

-- INSERT INTO ClassSchedule (schedule_id, class_id, day, start_time, end_time) VALUES
-- (1, 1, 'Monday', '09:00:00', '10:00:00'),  -- Adda class on Monday from 9:00 AM to 10:00 AM
-- (2, 2, 'Tuesday', '10:00:00', '11:00:00'), -- dbms class on Tuesday from 10:00 AM to 11:00 AM
-- (3, 3, 'Wednesday', '11:00:00', '12:00:00'), -- Graphics class on Wednesday from 11:00 AM to 12:00 PM
-- (4, 4, 'Thursday', '01:00:00', '02:00:00'); -- Disaster class on Thursday from 1:00 PM to 2:00 PM

-- INSERT INTO Grades (student_id, class_id, grade) VALUES
-- (1, 1, 'A'),  
-- (2, 2, 'A'),  
-- (3, 3, 'A'),  
-- (4, 4, 'A'),  
-- (2, 1, 'A'),  
-- (4, 3, 'A');  
