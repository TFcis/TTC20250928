# 超級加速度

\begin{figure}[h]
\centering
\includegraphics[width=5in]{Gemini_Generated_Image_pa6emupa6emupa6e.jpg}
\caption{Madfarm開賽車}
\end{figure}

經歷了 [TOJ7](https://toj.tfcis.org/oj/pro/7/) 的洗禮之後

Madfarm 準備開著他的紅色賽車進行實地演練

當然, 他肯定會想要秀一波大的

所以他的速度會變化非常大, 且很快到達終點並大喊

### Ballsdex

你身為一個觀察員, 必須要在他喊出 **Ballsdex** 的那個瞬間算出他的加加加加速度

但因為 Madfarm 實在太快了 所以你也要盡可能的快且精準的求出答案

\clearpage

## 輸入
給 $T$ 代表接下來有 $T$ 組測資

每一組的第一行會有一數 $N$ 

$N$ 的下一行會再給長度為 $N$ 的數列 $S$

## 輸出
輸出 $N-1$ 次差分後的結果 (差分到最後一個數字)

## 輸入限制
 - $1 \le T \le 1 * 10^5$
 - $1 \le N \le 100, \Sigma\ {N} \le 2 * 10^6$
 - $-2*10^6 \le S_i \le 2*10^6 \ (1 \le i \le N)$

## 子任務
\subtasks

\clearpage

## 範例輸入
\testfile{0-01.in}

## 範例輸出
\testfile{0-01.out}

## 範例測資解釋

對於第一組測資:
第一次差分:

```
9695-3227 3227-8902 8902-11304 11304-10000
```

```
6468 -5675 -2402 1304
```

第二次差分:

```
12143 -3273 -3706
```

第三次差分:

```
15416 433
```

第四次差分:

```
14983
```
