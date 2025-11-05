@echo off
echo Compiling...
gcc expense_tracker.c -o expense.exe
if exist expense.exe (
    echo Running Expense Tracker...
    echo ========================
    expense.exe
) else (
    echo Compile error!
)
pause
