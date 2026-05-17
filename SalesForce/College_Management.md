# College Management Lightning Application

## Project Overview
A Salesforce Lightning Application developed to manage **Student** and **Faculty** records with proper validation rules and a data validation system.

---

## Objective

This project includes:

- Student Object
- Faculty Object
- Validation Rules
- Lightning App
- Navigation Tabs
- Data Validation System

---

## Features

### Student Management

Custom Student Object with the following fields:

| Field Name | Data Type |
|----------|----------|
| Roll Number | Number |
| Email | Email |
| Department | Picklist |
| Marks | Number |
| Joining Date | Date |

### Department Picklist Values

- Computer
- IT
- Mechanical
- Civil
- ENTC
- Electrical

---

### Faculty Management

Custom Faculty Object with the following fields:

| Field Name | Data Type |
|----------|----------|
| Faculty ID | Number |
| Salary | Currency |
| Department | Picklist |
| Joining Date | Date |

---

## Validation Rules

### Student Validation Rules

#### 1. Roll Number Validation

```salesforce
Roll_Number__c <= 0
```

**Error Message:**  
Roll Number must be greater than 0

---

#### 2. Email Validation

```salesforce
NOT(CONTAINS(Email__c, "@"))
```

**Error Message:**  
Email must contain @ symbol

---

#### 3. Student Name Validation

```salesforce
ISBLANK(Name)
```

**Error Message:**  
Student name cannot be blank

---

#### 4. Marks Validation

```salesforce
OR(
    Marks__c < 0,
    Marks__c > 100
)
```

**Error Message:**  
Marks should be between 0 and 100

---

#### 5. Joining Date Validation

```salesforce
Joining_Date__c > TODAY()
```

**Error Message:**  
Joining Date cannot be future date

---

### Faculty Validation Rules

#### 1. Faculty Name Validation

```salesforce
LEN(Name) < 3
```

**Error Message:**  
Faculty Name must contain at least 3 characters

---

#### 2. Faculty ID Validation

```salesforce
Faculty_ID__c <= 0
```

**Error Message:**  
Faculty ID must be greater than 0

---

#### 3. Unique Faculty ID

Enable the **Unique** property for Faculty ID field.

---

#### 4. Salary Validation

```salesforce
OR(
    Salary__c <= 10000,
    Salary__c >= 500000
)
```

**Error Message:**  
Salary must be between 10,000 and 500,000

---

#### 5. Faculty Joining Date Validation

```salesforce
Joining_Date__c > TODAY()
```

**Error Message:**  
Joining Date cannot be future date

---

## Setup Instructions

### Step 1: Create Student Object

Navigate to:

```bash
Setup → Object Manager → Create → Custom Object
```

Enter:

- Label: Student
- Plural Label: Students
- Record Name: Student Name

---

### Step 2: Create Student Fields

Navigate to:

```bash
Student → Fields & Relationships → New
```

Create all student fields listed above.

---

### Step 3: Create Faculty Object

Navigate to:

```bash
Setup → Object Manager → Create → Custom Object
```

Enter:

- Label: Faculty
- Plural Label: Faculties
- Record Name: Faculty Name

---

### Step 4: Create Faculty Fields

Navigate to:

```bash
Faculty → Fields & Relationships → New
```

Create all faculty fields listed above.

---

### Step 5: Create Tabs

Navigate to:

```bash
Setup → Tabs → New
```

Create:

- Student Tab
- Faculty Tab

---

### Step 6: Create Lightning App

Navigate to:

```bash
Setup → App Manager → New Lightning App
```

App Name:

```bash
College Management
```

Click:

- Next
- Next
- Next

---

### Step 7: Add Navigation Items

Add:

- Students
- Faculties

Then click:

- Save & Finish

---

## Validation Testing

### Student Test Cases

| Test | Invalid Input | Expected Result |
|------|--------------|----------------|
| Roll Number | 0 | Error |
| Email | abcgmail.com | Error |
| Marks | 120 | Error |
| Joining Date | Future Date | Error |

---

### Faculty Test Cases

| Test | Invalid Input | Expected Result |
|------|--------------|----------------|
| Faculty Name | ab | Error |
| Faculty ID | 0 | Error |
| Duplicate Faculty ID | Existing ID | Error |
| Salary | 5000 | Error |
| Joining Date | Future Date | Error |

---

## Troubleshooting

### Student / Faculty Not Showing in Navigation

**Cause:**  
Tabs were not created.

**Solution:**

```bash
Setup → Tabs → New
```

Create:

- Student Tab
- Faculty Tab

Refresh the page and add navigation items again.

---

### App Not Opening

**Cause:**  
Searching inside Setup instead of App Launcher.

**Solution:**

1. Open **App Launcher (9 Dots)**
2. Search **College Management**
3. Open the application

---

## Final Output

Successfully implemented:

- Student Management System
- Faculty Management System
- Validation Rules
- Unique Faculty ID Validation
- Lightning App Navigation
- Record Forms
- Salesforce Lightning Experience

---

## Project Status

✅ COMPLETED SUCCESSFULLY