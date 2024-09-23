def count_possibilities(row):
    count = 0
    for i in range(len(row) - 2):
        if row[i] != row[i + 1] and row[i + 1] != row[i + 2] and row[i] != row[i + 2]:
            count += 1
    return count


def find_winner(ashok_row, anand_row):
    ashok_possibilities = count_possibilities(ashok_row)
    anand_possibilities = count_possibilities(anand_row)
    if ashok_possibilities > anand_possibilities:
        return "Ashok"
    elif anand_possibilities > ashok_possibilities:
        return "Anand"
    else:
        return "Draw"


ashok_row = input().strip()

anand_row = input().strip()

# Output

print(find_winner(ashok_row, anand_row), end='')
