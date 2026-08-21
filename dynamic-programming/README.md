# Dynamic Programming

這個資料夾記錄我使用 C++ 學習動態規劃的過程，包含基礎狀態轉移、記憶化搜尋、空間壓縮、背包問題、網格 DP 與樹形 DP。

所有程式都是在理解狀態定義、初始值與轉移方式後自行完成，並使用測試資料驗證。

## 核心觀念

寫 DP 前，我會先回答三個問題：

1. 狀態代表什麼？
2. 初始狀態是什麼？
3. 如何用已知的小問題答案推導目前答案？

## 練習程式

- [01_climbing_stairs_bottom_up.cpp](src/01_climbing_stairs_bottom_up.cpp)：Bottom-up 基礎
- [02_climbing_stairs_rolling.cpp](src/02_climbing_stairs_rolling.cpp)：空間壓縮
- [03_climbing_stairs_memoization.cpp](src/03_climbing_stairs_memoization.cpp)：記憶化搜尋
- [04_max_score_path_reconstruction.cpp](src/04_max_score_path_reconstruction.cpp)：最大值 DP 與路徑還原
- [05_frog_jump_min_cost.cpp](src/05_frog_jump_min_cost.cpp)：最小花費 DP
- [06_minimum_coin_change.cpp](src/06_minimum_coin_change.cpp)：INF 與無法到達狀態
- [07_knapsack_2d.cpp](src/07_knapsack_2d.cpp)：二維 0/1 背包
- [08_knapsack_1d.cpp](src/08_knapsack_1d.cpp)：一維背包與倒序更新
- [09_grid_path_count_2d.cpp](src/09_grid_path_count_2d.cpp)：二維網格 DP
- [10_grid_path_count_1d.cpp](src/10_grid_path_count_1d.cpp)：網格 DP 空間壓縮
- [11_max_non_adjacent_sum.cpp](src/11_max_non_adjacent_sum.cpp)：不相鄰位置的最大總和
- [12_tree_independent_set.cpp](src/12_tree_independent_set.cpp)：DFS 搭配樹形 DP
- [13_frog_jump_k.cpp](src/13_frog_jump_k.cpp)：多個前置狀態的轉移

## 驗證方式

所有程式皆使用 C++17 與 `g++ -std=c++17 -Wall -Wextra` 編譯。

編譯時沒有出現警告或錯誤，並使用一般情況、無法到達、障礙物與大數值等測試資料檢查主要邏輯。

## 學習反思

詳細內容請參考 [DP 學習反思](notes/01-dp-learning-notes.md)。