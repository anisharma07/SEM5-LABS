create table teams(
team_id INT PRIMARY KEY,
team_name varchar(100),
coach_name varchar(100),
city varchar(20)
);

create table stadiums(
stadium_id INT PRIMARY KEY,
stadium_name varchar(100),
location varchar(20),
capacity INT
);

create table players(
player_id INT PRIMARY KEY,
player_name varchar(100),
date_of_birth DATE,
team_id INT,
Nationality varchar(100)
);

create table matches(
match_id int primary key,
match_date Date,
stadium_id INT,
team1_id INT,
team2_id INT,
winner enum('team1', 'team2'),
score1 INT,
score2 INT
);

create table participants(
participant_id INT PRIMARY KEY,
match_id int,
player_id int,
player_position varchar(100),
minutes_played time,
foreign key (match_id) references matches(match_id),
foreign key (player_id) references players(player_id)
);
