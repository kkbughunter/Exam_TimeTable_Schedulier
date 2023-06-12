# Exam Timetable Scheduler

This project is a C program for generating an appropriate timetable for university exams based on the number of students and the availability of classes.

## Introduction
Examination timetable scheduling is a challenging task in every university system. This project aims to address the challenges of assigning examinations to venues over a period of time while satisfying all constraints. The objective is to design an algorithm that uses optimization algorithms and local search techniques to produce an effective timetable solution. This README provides an overview of the project, including its purpose, input, output, architectural diagram, techniques used, and references.

## Problem Statement
The goal is to create an appropriate timetable for university exams based on the number of students writing the exams and the availability of classes.

## Input
- File1: Contains student, staff, room, and course details.
- File2: Contains arrear course details.
- Date and Time.

### Terminal Input
![Terminal Input](https://user-images.githubusercontent.com/91019132/187713811-57f8f1f6-64bf-4552-a93b-8b4103a4d8ad.png)

### File Input
![File Input 1](https://user-images.githubusercontent.com/91019132/187718193-1dd4915c-7542-4e2d-8602-746bdf51a9bf.png)
![File Input 2](https://user-images.githubusercontent.com/91019132/187718216-6c49f534-6c65-43e9-8672-45d003c22b74.png)

## Output
The output is stored in a file in text format and includes the following timetables:
- Arrear Timetable
- Main Timetable
- Student Seating Timetable
- Invigilator Timetable

![Output](https://user-images.githubusercontent.com/91019132/187717807-5859705f-5308-4d59-aeaa-d6ee8906c85c.png)

## Architectural Diagram
![Architectural Diagram](https://user-images.githubusercontent.com/91019132/187066435-1408d6c3-d30d-465d-a020-36dd4ff2a7f4.png)

## Technique
The project utilizes the following techniques:
- Sorting
- File system
- Modular programming / data encapsulation
- Multiple aspects of the same data
- String initialization
- Application of structure copy
- Proper use of header files

## Soft Constraints Addressed
- A student should not have more than one exam in a day.
- The examination duration will not violate the assigned duration.
- In a room, students should be of the same department.
- The number of staff can be higher than required.

## References
- Final Exam Scheduling Timetable: A Case Study. Available from: [Link](https://www.researchgate.net/publication/273521527_Final_Exam_Scheduling_Timetable_a_Case_Study) [Accessed May 18, 2022].
- Komijan, A.R., Koupaei, M.N. A new binary model for university examination timetabling: a case study. J Ind Eng Int 8, 28 (2012). [DOI](https://doi.org/10.1186/2251-712X-8-28)

## Conclusion
Scheduling and planning are common challenges for universities, colleges, and schools. Generating a perfect timetable that satisfies all constraints is difficult. This project aims to minimize the conflicts in the timetable and reduce the overall cost of resources used.
