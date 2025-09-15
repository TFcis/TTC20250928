# 完美錢包

\begin{figure}[h]
\centering
\includegraphics[width=5in]{Gemini_Generated_Image_xgwbp6xgwbp6xgwb.png}
\caption{好吃的便當}
\end{figure}

Blame 很喜歡完美的東西
例如完全平方數
所以他規定自己錢包裡面的錢一定要是完全平方數
接下來幾天他想在美廣買 $N$ 元的便當, 但他不曉得自己應該要帶多少錢出去才是完美的
因此他想請你幫他計算他可以帶多少錢出去, 並且會剩下多少錢回來
為了方便記憶 跟他說平方根就行了

\clearpage

## 輸入
給 $T$ 代表接下來有 $T$ 組測資
每一組會有一數 $N$

## 輸出
要輸出兩整數 $A, B$ 使得 $A^2\ -\ N = B^2$
如果沒有要輸出 $-1$

**注意**: 請不要輸出超過 long long 的範圍, 不然 checker 會判你錯

## 輸入限制
- $1 \le T \le 1 * 10^5$
- $0 \le |N| \le 1*10^{18}$

## 子任務
\subtasks

\clearpage

## 範例輸入
\testfile{0-01.in}

## 範例輸出
\testfile{0-01.out}

## 範例測資解釋

1. $(-7)^2 - 5^2 = 49 - 25 = 24$
2. $3^2 - 8^2 = 9 - 64 = -55$
3. $10^2 - 10^2 = 0$
