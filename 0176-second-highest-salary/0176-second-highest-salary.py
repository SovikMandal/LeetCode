import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    first = float("-inf")
    second = float("-inf")

    for salary in employee["salary"]:
        if salary > first:
            second = first
            first = salary
        elif first > salary > second:
            second = salary

    if second == float("-inf"):
        return pd.DataFrame({"SecondHighestSalary": [None]})

    return pd.DataFrame({"SecondHighestSalary": [second]})