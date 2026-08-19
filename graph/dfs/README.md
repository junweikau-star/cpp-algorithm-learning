資料夾記錄從基礎遞迴 DFS，到連通元件、環偵測、網格搜尋與樹上 DFS 的學習過程。



\## 練習內容



| 檔案 | 主題 |

|---|---|

| `01\_recursive\_dfs\_traversal.cpp` | 遞迴 DFS 走訪 |

| `02\_connected\_components.cpp` | 計算連通元件 |

| `03\_undirected\_cycle\_detection.cpp` | 無向圖偵測環 |

| `04\_grid\_connected\_components.cpp` | 網格連通區域 |

| `05\_iterative\_dfs.cpp` | 使用 stack 的非遞迴 DFS |

| `06\_tree\_depth.cpp` | 計算樹上深度 |

| `07\_subtree\_size.cpp` | 計算子樹大小 |

| `08\_minimum\_tree\_split.cpp` | 刪除一條樹邊，使兩側大小差最小 |



\## 核心觀念



\- DFS 會先沿著一條路深入，無路可走時再回溯。

\- 進入節點時要立刻標記，避免重複搜尋。

\- 無向圖偵測環時，要分辨父節點與其他已拜訪節點。

\- 樹上 DFS 可以在孩子返回後，由下往上合併子樹資訊。

\- 遞迴太深可能造成 stack overflow，可改用 `std::stack`。



\## 複雜度



使用鄰接表時，DFS 的時間複雜度為 `O(V+E)`；網格 DFS 為 `O(H×W)`。

