-- CREATE TABLE Instructor (InstructorID INT PRIMARY KEY, Name VARCHAR(100), Contact VARCHAR(15));

-- CREATE TABLE Course (CourseID INT PRIMARY KEY, CourseName VARCHAR(100), Credits INT);

-- CREATE TABLE Room (RoomID INT PRIMARY KEY, RoomNumber VARCHAR(10), Capacity INT);

-- CREATE TABLE Class (
--     ClassID INT PRIMARY KEY, ClassName VARCHAR(50), CourseID INT, InstructorID INT, RoomID INT, FOREIGN KEY (CourseID) REFERENCES Course(CourseID), 
--     FOREIGN KEY (InstructorID) REFERENCES Instructor(InstructorID), FOREIGN KEY (RoomID) REFERENCES Room(RoomID)
--     );

-- CREATE TABLE TimeTable (
--     TimeTableID INT PRIMARY KEY, ClassID INT, DayOfWeek VARCHAR(10), StartTime TIME, EndTime TIME, FOREIGN KEY (ClassID) REFERENCES Class(ClassID)
--     );

-- -- Insert Instructors
-- INSERT INTO Instructor VALUES (1, 'Dr. Smith', '1234567890');
-- INSERT INTO Instructor VALUES (2, 'Prof. Johnson', '0987654321');

-- -- Insert Courses
-- INSERT INTO Course VALUES (1, 'Mathematics', 3);
-- INSERT INTO Course VALUES (2, 'Physics', 4);

-- -- Insert Rooms
-- INSERT INTO Room VALUES (1, 'Room 101', 30);
-- INSERT INTO Room VALUES (2, 'Room 102', 25);

-- -- Insert Classes
-- INSERT INTO Class VALUES (1, 'Math Class A', 1, 1, 1);
-- INSERT INTO Class VALUES (2, 'Physics Class B', 2, 2, 2);

-- -- Insert Time Table
-- INSERT INTO TimeTable VALUES (1, 1, 'Monday', '09:00:00', '10:30:00');
-- INSERT INTO TimeTable VALUES (2, 2, 'Tuesday', '11:00:00', '12:30:00');
