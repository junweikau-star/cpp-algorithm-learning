# Dijkstra

這個資料夾記錄我使用 C++ 學習 priority queue 與 Dijkstra 最短路徑演算法的過程。

內容包含一般加權圖、路徑還原、加權網格，以及加入通行券狀態的 Dijkstra。

## 使用條件

Dijkstra 適合處理邊權重皆為非負數的圖。

如果所有邊的權重都相同，可以使用時間複雜度較低的 BFS。若圖中可能有負權重，則不能直接套用標準 Dijkstra。

## 核心觀念

- 使用最小 priority queue 優先處理目前距離最小的狀態
- 將起點距離設為 0，其他節點設為 INF
- 使用鬆弛更新相鄰節點的最短距離
- 取出狀態時跳過已經過期的資料
- 使用 parent 還原最短路徑
- 使用 long long 避免距離累積時溢位
- 將額外條件加入狀態，處理通行券等進階問題

## 練習程式

- [Priority queue 基本操作](src/01_priority_queue_practice.cpp)
- [一般 Dijkstra 與路徑還原](src/02_dijkstra_path_reconstruction.cpp)
- [加權網格 Dijkstra](src/03_weighted_grid_dijkstra.cpp)
- [通行券狀態 Dijkstra](src/04_coupon_state_dijkstra.cpp)

## 複雜度

- 一般加權圖時間：`O((n + m) log n)`
- 一般加權圖空間：`O(n + m)`
- 加權網格時間：`O(H * W * log(H * W))`
- 加權網格空間：`O(H * W)`

## 驗證方式

所有程式皆使用 C++17 與 `g++ -std=c++17 -Wall -Wextra` 編譯。

程式使用一般路徑、不可達、起終點相同、大型權重與狀態擴充等測試資料驗證。

## 學習反思

詳細內容請參考 [Dijkstra 學習反思](notes/01-dijkstra-learning-notes.md)。
