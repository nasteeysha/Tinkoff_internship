def max_remaining_burles(n, m, gift_prices):
    # Сортируем цены подарков по убыванию
    sorted_prices = sorted(gift_prices, reverse=True)

    # Находим оптимальный размер кредита
    max_remaining = 0
    for credit in range(m + 1):
        remaining = credit
        for price in sorted_prices:
            if remaining >= price:
                remaining -= price
        max_remaining = max(max_remaining, remaining)
    
    return max_remaining

n, m = map(int, input().split())
gifts = list(map(int, input().split()))

result = max_remaining_burles(n, m, gifts)
print(result)
def max_remaining_burles(n, m, gift_prices):
    # Сортируем цены подарков по убыванию
    sorted_prices = sorted(gift_prices, reverse=True)

    # Находим оптимальный размер кредита
    max_remaining = 0
    for credit in range(m + 1):
        remaining = credit
        for price in sorted_prices:
            if remaining >= price:
                remaining -= price
        max_remaining = max(max_remaining, remaining)
    
    return max_remaining

n, m = map(int, input().split())
gifts = list(map(int, input().split()))

result = max_remaining_burles(n, m, gifts)
print(result)