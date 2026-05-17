# College Management Lightning Application

## Project Title
Develop a College Management Lightning Application to store and manage Student and Faculty records with validation rules.

---

## Objective

Create:

- Student Object
- Faculty Object
- Validation Rules
- Lightning App
- Tabs
- Data Validation System

---

# Step 1: Create Student Object

Go to:

Setup → Object Manager → Create → Custom Object

Enter the following details:

| Field | Value |
|------|------|
| Label | Student |
| Plural Label | Students |
| Record Name | Student Name |

Click **Save**.

---

# Step 2: Create Student Fields

Go to:

Student → Fields & Relationships → New

Create the following fields:

| Field Name | Data Type |
|----------|----------|
| Roll Number | Number |
| Email | Email |
| Department | Picklist |
| Marks | Number |
| Joining Date | Date |

---

# Step 3: Department Picklist Values

Add the following values:

- Computer
- IT
- Mechanical
- Civil
- ENTC
- Electrical

Click **Save**.

---

# Step 4: Create Faculty Object

Go to:

Setup → Object Manager → Create → Custom Object

Enter the following details:

| Field | Value |
|------|------|
| Label | Faculty |
| Plural Label | Faculties |
| Record Name | Faculty Name |

Click **Save**.

---

# Step 5: Create Faculty Fields

Go to:

Faculty → Fields & Relationships → New

Create the following fields:

| Field Name | Data Type |
|----------|----------|
| Faculty ID | Number |
| Salary | Currency |
| Department | Picklist |
| Joining Date | Date |

---

# Step 6: Student Validation Rules

## 1. Roll Number Validation

**Rule Name:** `Roll_Number_Validation`

**Formula:**

```salesforce
Roll_Number__c <= 0
```

**Error Message:**  
Roll Number must be greater than 0

---

## 2. Email Validation

**Rule Name:** `Email_Validation`

**Formula:**

```salesforce
NOT(CONTAINS(Email__c, "@"))
```

**Error Message:**  
Email must contain @ symbol

---

## 3. Student Name Validation

**Rule Name:** `Student_Name_Validation`

**Formula:**

```salesforce
ISBLANK(Name)
```

**Error Message:**  
Student name cannot be blank

---

## 4. Marks Validation

**Rule Name:** `Marks_Validation`

**Formula:**

```salesforce
OR(
    Marks__c < 0,
    Marks__c > 100
)
```

**Error Message:**  
Marks should be between 0 and 100

---

## 5. Joining Date Validation

**Rule Name:** `Joining_Date_Validation`

**Formula:**

```salesforce
Joining_Date__c > TODAY()
```

**Error Message:**  
Joining Date cannot be future date

---

# Step 7: Faculty Validation Rules

## 1. Faculty Name Validation

**Rule Name:** `Faculty_Name_Validation`

**Formula:**

```salesforce
LEN(Name) < 3
```

**Error Message:**  
Faculty Name must contain at least 3 characters

---

## 2. Faculty ID Validation

**Rule Name:** `Faculty_ID_Validation`

**Formula:**

```salesforce
Faculty_ID__c <= 0
```

**Error Message:**  
Faculty ID must be greater than 0

---

## 3. Make Faculty ID Unique

Go to:

Faculty → Fields & Relationships → Faculty ID → Edit

Enable:

- Unique

Click **Save**.

---

## 4. Salary Validation

**Rule Name:** `Salary_Validation`

**Formula:**

```salesforce
OR(
    Salary__c <= 10000,
    Salary__c >= 500000
)
```

**Error Message:**  
Salary must be between 10,000 and 500,000

---

## 5. Faculty Joining Date Validation

**Rule Name:** `Faculty_Joining_Date_Validation`

**Formula:**

```salesforce
Joining_Date__c > TODAY()
```

**Error Message:**  
Joining Date cannot be future date

---

# Step 8: Create Tabs

## Problem Faced

Student and Faculty objects were not appearing in Navigation Items.

## Reason

Tabs were not created.

## Solution

Go to:

Setup → Tabs → New

Create:

- Student Tab
- Faculty Tab

Choose any tab style.

Click **Save**.

---

# Step 9: Create Lightning App

Go to:

Setup → App Manager → New Lightning App

Enter:

**App Name:** College Management

Continue clicking:

- Next
- Next
- Next

---

# Step 10: Navigation Items Problem

## Error Faced

Students and Faculties were not visible in Navigation Items.

## Solution

After creating tabs:

1. Refresh page
2. Search Students
3. Add using Arrow button
4. Add Faculties
5. Click Next
6. Save & Finish

---

# Step 11: App Not Opening Problem

## Error Faced

College Management app not opening.

## Reason

Search was performed inside Setup instead of App Launcher.

## Correct Method

1. Click **9 Dots (App Launcher)**
2. Search **College Management**
3. Open the app

---

# Step 12: Final Working Output

Successfully Working:

- Student Object
- Faculty Object
- Validation Rules
- Lightning App
- Tabs
- Record Forms

---

# Step 13: Validation Testing

## Student Validation Tests

| Test | Wrong Value | Expected Result |
|------|------------|----------------|
| Roll Number | 0 | Error |
| Email | abcgmail.com | Error |
| Marks | 120 | Error |
| Joining Date | Future Date | Error |

---

## Faculty Validation Tests

| Test | Wrong Value | Expected Result |
|------|------------|----------------|
| Faculty Name | ab | Error |
| Faculty ID | 0 | Error |
| Duplicate Faculty ID | Existing ID | Error |
| Salary | 5000 | Error |
| Joining Date | Future Date | Error |

---

# Final Conclusion

The College Management Lightning Application was successfully implemented with:

- Student Management
- Faculty Management
- Validation Rules
- Unique Faculty ID Validation
- Lightning App Navigation
- Salesforce Lightning Experience
- Data Accuracy Validation System

## Project Status

✅ COMPLETED SUCCESSFULLY