def find_min_cost_to_buy_all_shares(tree, root, company_names, n, k):
    # Функция для вычисления минимальной стоимости поддерева, содержащего все акции
    def dfs(node, parent):
        total_cost = tree[node][1]
        companies = {tree[node][2]}

        for child in children[node]:
            if child == parent:
                continue
            cost, child_companies = dfs(child, node)
            total_cost += cost
            companies |= child_companies

        if companies == company_names:
            nonlocal min_cost
            min_cost = min(min_cost, total_cost)
        
        return total_cost, companies

    # Строим список детей для каждой вершины
    children = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        children[tree[i][0]].append(i)

    min_cost = float('inf')
    company_names = set(company_names)
    dfs(root, -1)

    return min_cost if min_cost != float('inf') else -1

n, k = map(int, input().split())
company_names = set(input() for _ in range(k))
tree = {}

for i in range(1, n + 1):
    parent, cost, company = input().split()
    tree[i] = [int(parent), int(cost), company]

# Определение корня дерева (вершина без родителя)
root = next(i for i in range(1, n + 1) if tree[i][0] == 0)

# Вызов функции и вывод результата
min_cost = find_min_cost_to_buy_all_shares(tree, root, company_names, n, k)
print(min_cost)

# Вызов функции
find_min_cost_to_buy_all_shares(tree, 1, company_names, n, k)