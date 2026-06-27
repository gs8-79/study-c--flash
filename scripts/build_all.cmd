@echo off
setlocal

set ROOT=%~dp0..
set SRC=%ROOT%\src
set BUILD=%ROOT%\build

if not exist "%BUILD%" mkdir "%BUILD%"

cl /EHsc /std:c++17 /Fo"%BUILD%\01_foundation_temperature.obj" /Fe"%BUILD%\01_foundation_temperature.exe" "%SRC%\01_foundation_temperature.cpp"
if errorlevel 1 exit /b 1

cl /EHsc /std:c++17 /Fo"%BUILD%\02_point_date_employee.obj" /Fe"%BUILD%\02_point_date_employee.exe" "%SRC%\02_point_date_employee.cpp"
if errorlevel 1 exit /b 1

cl /EHsc /std:c++17 /Fo"%BUILD%\03_shapes_polymorphism.obj" /Fe"%BUILD%\03_shapes_polymorphism.exe" "%SRC%\03_shapes_polymorphism.cpp"
if errorlevel 1 exit /b 1

cl /EHsc /std:c++17 /Fo"%BUILD%\04_file_exception.obj" /Fe"%BUILD%\04_file_exception.exe" "%SRC%\04_file_exception.cpp"
if errorlevel 1 exit /b 1

cl /EHsc /std:c++17 /Fo"%BUILD%\05_mock_exam_solution.obj" /Fe"%BUILD%\05_mock_exam_solution.exe" "%SRC%\05_mock_exam_solution.cpp"
if errorlevel 1 exit /b 1

echo Build succeeded.
endlocal
