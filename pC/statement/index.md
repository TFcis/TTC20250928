# 這一定是特性

\begin{figure}[h]
\centering
\includegraphics[width=5in]{Gemini_Generated_Image_tts5bztts5bztts5.jpg}
\caption{充滿bug的minecraft}
\end{figure}

眾所周知, Mincraft 是一款充滿 bug... 阿不是, 是充滿特性的遊戲, 有一天, 你無意間發現了一個重大特性, 經過劈哩啪啦一連串操作後, 可以更改方塊任意位置的位元, 其運作方式如下:

**將第 i 個位元替換成第 i-1 及 i+1 的 nxor 值**

**若在前端或末端則會替換成鄰近那個數字的not值**

因此你決定拿最多的空氣方塊來產生出任意方塊

Wonderhoi 也想拿到一些方塊

所以找你幫忙, 請你跟他說說產生他要的方塊的步驟吧

精確的說:

有一個長度為 $N$ 的 $01$ 字串

字串可以進行以下操作:

將第 $i\ (2 \le i \le N-1)$ 個位元替換成第 $i-1$ 及 $i+1$ 的 nxor 值

若 $i = 1\ or\ N$ 則會替換成鄰近那個位元的not值

你的目標是要找出可能的操作步驟使得 每個字元皆是 $0$ 的 $0$ 字串變成給定的字串 

what is nxor?

簡單的說 就是反的xor

0 nxor 0 = 1, 0 nxor 1 = 0, 1 nxor 0 = 0, 1 nxor 1 = 1

\clearpage

## 輸入
第一行會有一數 $N$

代表接下來有長度為 $N$ 的 $01$ 字串

字串可以進行以下操作:

將第 $i\ (2 \le i \le N-1)$ 個位元替換成第 $i-1$ 及 $i+1$ 的 nxor 值

若 $i = 1\ or\ N$ 則會替換成鄰近那個位元的not值

## 輸出

請先輸出你的操作次數

再依序輸出操作位置 $i$

如果無法經由任意操作達成目標請輸出 $-1$

操作次數請勿超過 $1 \cdot 10^8$ 不然會被嗆

## 輸入限制
 - $2 \le N \le 1 \cdot 10^6$
 - $S_i \in \{0,\ 1\} \ (1 \le i \le N)$

## 子任務
\subtasks

\clearpage

## 範例輸入1
\testfile{0-01.in}

## 範例輸出1
\testfile{0-01.out}

## 範例測資解釋1
有五步

000000 -> 000100 -> 010100 -> 011100 -> 011000 -> 011010

## 範例輸入2
\testfile{0-02.in}

## 範例輸出2
\testfile{0-02.out}

## 範例測資解釋2
會發現不管怎麼操作都不會變, 所以應輸出 $-1$

## 範例輸入3
\testfile{0-03.in}

## 範例輸出3
\testfile{0-03.out}

