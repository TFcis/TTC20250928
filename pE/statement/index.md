# I Hateth Thee, Master of GCD

\begin{figure}[h]
\centering
\includegraphics[width=5in]{Gemini_Generated_Image_ad1m0aad1m0aad1m.jpg}
\caption{寫滿算式的黑板}
\end{figure}

Upon a certain day, Wonderhoi did attend a lesson of numbers.

The master, Sir Dirichlet, did expound unto his pupils a cunning art whereby one might swiftly discern the greatest common divisor (gcd) of two numbers:

```
First, taketh the lesser of the twain.
Then substract the lesser from the greater, until the greater falleth beneath the lesser.  
Thereafter, exchange their places, and repeat the process anon.  
Continue thus, until one number falleth unto naught; the other then remaineth, and that is the gcd of the two from the beginning.
```

As all masters are wont to do, Sir Dirichlet would prove whether Wonderhoi had grasped this craft.

Therefore he gave this task:

$$
\sum_{i=1}^{n} \sum_{j=1}^{m} \gcd(i,j)
$$

Yet Wonderhoi, deeming it but a trifle, did resolve it in but half a heartbeat.
Straightway he did turn the tables, and set forth many new riddles, such as this:

$$
\sum_{i=1}^{n} \sum_{j=1}^{m} \varphi(\gcd(i,j))
$$

Here, $\varphi$ is hight the Euler’s totient function.


Alas, this question did confound even Master Dirichlet himself.

Thus he did call upon Wonderhoi’s truest companion—*thee*—to lend thy wit.

Wilt thou succour him?

怕你看不懂中世紀英文, 所以這裡提供簡易中文版給你參考

一開始給一數 $T$ 代表接下來有 $T$ 行

接下來每一行有一個數字 $N$

求 $\sum\limits_{i\ =\ 1}^n{\sum\limits_{j\ =\ 1}^m{\varphi (gcd(i,j))}}$

$\varphi$ 為歐拉函數

\clearpage

## 輸入
一開始給一數 $T$ 代表接下來有 $T$ 行

接下來每一行有兩個數字 $n, m$

## 輸出
輸出 $\sum\limits_{i\ =\ 1}^n{\sum\limits_{j\ =\ 1}^m{\varphi (gcd(i,j))}}$
$\varphi$ 為歐拉函數

## 輸入限制
 - $1 \le T \le 2*10^{4}$
 - $1 \le n,\ m \le 1*10^{6}$

## 子任務
\subtasks

\clearpage

## 範例輸入1
\testfile{0-01.in}

## 範例輸出1
\testfile{0-01.out}

## 範例測資解釋

第一筆:

$\varphi (gcd(1, 1)) = \varphi (1) = 1$

第二筆:

$\varphi (gcd(1, 1)) + \varphi (gcd(1, 2)) + \varphi (gcd(1, 3)) + \varphi (gcd(1, 4))$

$+ \varphi (gcd(2, 1)) + \varphi (gcd(2, 2)) + \varphi (gcd(2, 3)) + \varphi (gcd(2, 4))$

$+ \varphi (gcd(3, 1)) + \varphi (gcd(3, 2)) + \varphi (gcd(3, 3)) + \varphi (gcd(3, 4))$

$= \varphi (1) + \varphi (1) + \varphi (1) + \varphi (1) + \varphi (1) + \varphi (2)$

$+ \varphi(1) + \varphi (2) + \varphi (1) + \varphi (1) + \varphi (3) + \varphi (1)$

$= 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 2 + 1 = 13$

第三筆:

$\varphi (gcd(1, 1)) + \varphi (gcd(2, 1)) = \varphi (1) + \varphi (1) = 1 + 1 = 2$

## 範例輸入2
\testfile{0-02.in}

## 範例輸出2
\testfile{0-02.out}

