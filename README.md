# C++ Algorithm Learning Journey

這個 repository 記錄我使用 C++ 學習競技程式設計演算法的過程，包含觀念筆記、練習程式、除錯經驗與學習反思，並將部分演算法翻譯成 JavaScript 製作互動視覺化。

## 學習目標

1. 建立圖論與動態規劃的基礎
2. 熟悉 C++ STL 與競程常用資料結構
3. 練習分析時間與空間複雜度
4. 透過 GitHub 保存可驗證的學習歷程

## 代表成果

- [BFS 與 Dijkstra 加權網格視覺化](visualizer/README.md)：使用同一張加權網格，比較最少步數與最小總成本的路徑差異。

## 專案結構

- `graph/bfs/`：BFS 程式、筆記與學習反思
- `graph/dfs/`：DFS 程式、筆記與學習反思
- `dynamic-programming/`：DP 程式、筆記與學習反思
- `graph/dijkstra/`：Priority queue、Dijkstra 程式、筆記與學習反思
- `visualizer/`：BFS 與 Dijkstra 加權網格視覺化

## 已完成主題

### BFS

- 單源 BFS 與無權圖最短距離
- 二維網格與多源 BFS
- 帶有破牆狀態的 BFS
- 最短路徑還原

詳細內容請參考 [BFS 學習紀錄](graph/bfs/README.md)。

### DFS

- 遞迴與非遞迴 DFS
- 計算連通元件
- 無向圖偵測環
- 網格連通區域
- 樹的深度與子樹大小
- 使用子樹資訊解決樹切割問題

詳細內容請參考 [DFS 學習紀錄](graph/dfs/README.md)。

### Dynamic Programming

- Bottom-up、Top-down 與記憶化搜尋
- 最大值、最小值與路徑還原
- 最少硬幣與 0/1 背包
- 網格 DP 與空間壓縮
- DFS 搭配樹形 DP

詳細內容請參考 [DP 學習紀錄](dynamic-programming/README.md)。

### Dijkstra

- Priority queue 最大堆與最小堆
- 一般非負加權圖最短路徑
- 過期狀態判斷與路徑還原
- 加權網格 Dijkstra
- 通行券狀態擴充 Dijkstra

詳細內容請參考 [Dijkstra 學習紀錄](graph/dijkstra/README.md)。

## 學習方式

每個主題會依序進行：

1. 理解核心觀念
2. 手動推演演算法
3. 自己完成 C++ 實作
4. 使用測試資料驗證
5. 記錄錯誤、修正原因與反思
6. 將部分演算法翻譯成 JavaScript，透過動畫比較演算法行為

## 下一步

- 學習拓撲排序
- 練習 DAG 上的動態規劃
- 加強獨立辨認演算法與狀態設計
- 嘗試圖論與 DP 的綜合題目