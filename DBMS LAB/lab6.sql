
-- CREATE TABLE Student (
--   StudentID INT PRIMARY KEY, Name VARCHAR(100), DOB DATE, Contact VARCHAR(15), Address VARCHAR(255), Gender CHAR(1), Email VARCHAR(100), EnrollmentDate DATE
--   );

-- CREATE TABLE Department (
--   DepartmentID INT PRIMARY KEY, DepartmentName VARCHAR(100),  HeadOfDepartment VARCHAR(100)
--   );

-- CREATE TABLE Course (
--   CourseID INT PRIMARY KEY,  CourseName VARCHAR(100), Credits INT, DepartmentID INT, FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
-- );

-- CREATE TABLE Instructor (
--   InstructorID INT PRIMARY KEY, Name VARCHAR(100),  DepartmentID INT, Contact VARCHAR(15),  Email VARCHAR(100), 
--   FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID) 
--   );
--   
-- CREATE TABLE Enrollment (
--   EnrollmentID INT PRIMARY KEY, StudentID INT, CourseID INT, EnrollmentDate DATE, Grade CHAR(2),
--   FOREIGN KEY (StudentID) REFERENCES Student(StudentID), FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
-- );

-- CREATE TABLE Exam (
--   ExamID INT PRIMARY KEY, CourseID INT, Date DATE, ExamType VARCHAR(50), MaxMarks INT, FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
-- );

-- CREATE TABLE Attendance (
--   AttendanceID INT PRIMARY KEY, StudentID INT,  CourseID INT, Date DATE, Status CHAR(1),
--   FOREIGN KEY (StudentID) REFERENCES Student(StudentID), FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
-- );

-- INSERT INTO Student (StudentID, Name, DOB, Contact, Address, Gender, Email, EnrollmentDate)
-- VALUES
-- (201, 'Alice Johnson', '2002-05-14', '4567890123', '123 Elm Street', 'F', 'alice.j@university.com', '2022-08-20'),
-- (202, 'Bob Miller', '2001-11-22', '5678901234', '456 Oak Avenue', 'M', 'bob.m@university.com', '2022-08-21'),
-- (203, 'Charlie Davis', '2003-01-10', '6789012345', '789 Pine Road', 'M', 'charlie.d@university.com', '2022-08-22'),
-- (204, 'Dana Smith', '2002-03-17', '7890123456', '135 Maple Lane', 'F', 'dana.s@university.com', '2022-08-23');

-- INSERT INTO Department (DepartmentID, DepartmentName, HeadOfDepartment)
-- VALUES
-- (1, 'Computer Science', 'Dr. John Doe'), (2, 'Mathematics', 'Dr. Jane Smith'), (3, 'Physics', 'Dr. Emily Brown');

-- INSERT INTO Course (CourseID, CourseName, Credits, DepartmentID)
-- VALUES
-- (101, 'Data Structures', 4, 1), (102, 'Calculus', 3, 2), (103, 'Quantum Physics', 4, 3), (104, 'Algorithms', 4, 1), (105, 'Linear Algebra', 3, 2);

-- INSERT INTO Instructor (InstructorID, Name, DepartmentID, Contact, Email)
-- VALUES
-- (1, 'Dr. Alan Turing', 1, '1234567890', 'turing@university.com'),
-- (2, 'Dr. Isaac Newton', 2, '2345678901', 'newton@university.com'),
-- (3, 'Dr. Albert Einstein', 3, '3456789012', 'einstein@university.com');

-- INSERT INTO Enrollment (EnrollmentID, StudentID, CourseID, EnrollmentDate, Grade)
-- VALUES
-- (301, 201, 101, '2022-09-01', 'A'), (302, 202, 102, '2022-09-02', 'B+'), (303, 203, 103, '2022-09-03', 'B'),
-- (304, 204, 101, '2022-09-01', 'A-'), (305, 201, 104, '2022-09-05', 'B+'), (306, 202, 105, '2022-09-06', 'A'),
-- (307, 203, 101, '2022-09-07', 'A-');

-- INSERT INTO Exam (ExamID, CourseID, Date, ExamType, MaxMarks)
-- VALUES
-- (401, 101, '2022-12-10', 'Midterm', 100), (402, 102, '2022-12-11', 'Midterm', 100), (403, 103, '2022-12-12', 'Midterm', 100),
-- (404, 104, '2022-12-13', 'Midterm', 100), (405, 105, '2022-12-14', 'Midterm', 100);

-- INSERT INTO Attendance (AttendanceID, StudentID, CourseID, Date, Status)
-- VALUES
-- (501, 201, 101, '2022-09-05', 'P'), (502, 202, 102, '2022-09-05', 'P'), (503, 203, 103, '2022-09-05', 'A'), 
-- (504, 204, 101, '2022-09-06', 'P'), (505, 201, 104, '2022-09-06', 'P'), (506, 202, 105, '2022-09-07', 'P');


-- SELECT S.Name, E.EnrollmentDate, E.Grade
-- FROM Student S
-- JOIN Enrollment E ON S.StudentID = E.StudentID
-- WHERE E.CourseID = 101;
--  
-- SELECT S.Name, A.Date, A.Status
-- FROM Student S
-- JOIN Attendance A ON S.StudentID = A.StudentID
-- WHERE A.CourseID = 103;
