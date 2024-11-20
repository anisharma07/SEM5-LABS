

-- CREATE TABLE Student (
--   StudentID INT PRIMARY KEY, Name VARCHAR(100), Email VARCHAR(100), Contact VARCHAR(15),  Gender CHAR(1), Address VARCHAR(255), EnrollmentDate DATE
-- );

-- CREATE TABLE Course (
--   CourseID INT PRIMARY KEY, CourseName VARCHAR(100), Credits INT
-- );

-- CREATE TABLE Instructor (
--   InstructorID INT PRIMARY KEY, Name VARCHAR(100), Department VARCHAR(100), Email VARCHAR(100)
-- );

-- CREATE TABLE Exam (
--   ExamID INT PRIMARY KEY,  CourseID INT, Date DATE, ExamType VARCHAR(50), FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
-- );

-- CREATE TABLE Result (
--   ResultID INT PRIMARY KEY, ExamID INT, StudentID INT, Grade CHAR(2), FOREIGN KEY (ExamID) REFERENCES Exam(ExamID), FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
-- );

-- CREATE TABLE Alert (
--   AlertID INT PRIMARY KEY, StudentID INT, AlertMessage VARCHAR(255), AlertDate DATE, FOREIGN KEY (StudentID) REFERENCES Student(StudentID)
-- );

-- INSERT INTO Student (StudentID, Name, Email, Contact, Gender, Address, EnrollmentDate)
-- VALUES
-- (201, 'Alice Johnson', 'alice.j@university.com', '1234567890', 'F', '123 Elm St', '2022-08-20'),
-- (202, 'Bob Miller', 'bob.m@university.com', '2345678901', 'M', '456 Oak Ave', '2022-08-21'),
-- (203, 'Charlie Davis', 'charlie.d@university.com', '3456789012', 'M', '789 Pine Rd', '2022-08-22');

-- INSERT INTO Course (CourseID, CourseName, Credits)
-- VALUES
-- (101, 'Data Structures', 4), (102, 'Calculus', 3), (103, 'Quantum Physics', 4);

-- INSERT INTO Instructor (InstructorID, Name, Department, Email)
-- VALUES
-- (301, 'Dr. Alan Turing', 'Computer Science', 'turing@university.com'), (302, 'Dr. Isaac Newton', 'Mathematics', 'newton@university.com'),
-- (303, 'Dr. Albert Einstein', 'Physics', 'einstein@university.com');

-- INSERT INTO Exam (ExamID, CourseID, Date, ExamType)
-- VALUES
-- (401, 101, '2023-05-10', 'Midterm'), (402, 102, '2023-05-12', 'Midterm'), (403, 103, '2023-05-14', 'Final');

-- INSERT INTO Result (ResultID, ExamID, StudentID, Grade)
-- VALUES
-- (501, 401, 201, 'A'), (502, 402, 202, 'B+'), (503, 403, 203, 'A-'), 
-- (504, 401, 202, 'B'), (505, 402, 201, 'A'), (506, 403, 201, 'A+');

-- INSERT INTO Alert (AlertID, StudentID, AlertMessage, AlertDate)
-- VALUES
-- (601, 201, 'Your result for exam 401 (Data Structures) is now available.', '2023-05-11'),
-- (602, 202, 'Your result for exam 402 (Calculus) is now available.', '2023-05-13'),
-- (603, 203, 'Your result for exam 403 (Quantum Physics) is now available.', '2023-05-15');

-- SELECT C.CourseName, E.ExamType, R.Grade
-- FROM Result R
-- JOIN Exam E ON R.ExamID = E.ExamID
-- JOIN Course C ON E.CourseID = C.CourseID
-- WHERE R.StudentID = 201;

-- SELECT AlertMessage, AlertDate
-- FROM Alert
-- WHERE StudentID = 201;
