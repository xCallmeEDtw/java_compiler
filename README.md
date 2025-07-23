# mini java compiler

## 運行環境
Lex 版本: flex 2.6.4
Yacc 版本: bison (GNU Bison) 3.8.2
OS: ubuntu 22.04
## 執行方式
1.	Compile : 
$ make clean
$ make
2.	Execute:
$ ./myjavac <inputfile>
e.g. $ ./myjavac ./tes1.java


## 測試結果：
test1.java
![j1](https://hackmd.io/_uploads/BysqvGAUxe.png)

test2.java
 

![jj2](https://hackmd.io/_uploads/BJs2wG08le.png)


test3.java

![j3](https://hackmd.io/_uploads/SyM3vfR8lg.png)

test4.java
	 
![j4](https://hackmd.io/_uploads/Hy_pvfRLge.png)



test5.java

![jj5](https://hackmd.io/_uploads/H1yavzRLge.png)

test6.java
	 
![j66](https://hackmd.io/_uploads/HJN6wzCUge.png)


## 如何處理這份規格書上的問題
	在文法 <Program> ::= class <ClassName> { <MemberList> } 中，
定義 Java 類別的基本架構。包含：
•	class 關鍵字遺漏
•	{ 或 } 括號缺漏
•	類別主體 <MemberList> 為空時，視情況顯示提示
•	不合法的類別名稱識別字
•	漏寫分號、括號不對稱、參數遺漏、重複宣告等問題，讓語法分析器具備基礎的錯誤恢復能力。
這些錯誤會被攔截處理，印出錯誤訊息，且不會導致 parser 直接終止。


	在文法 <Declaration> ::= <Type> <IDList> ; 中，檢查變數宣告的格式是否正確，包括漏寫分號、錯用 = 或 := 賦值符號等錯誤情況，並透過語意分析階段回報具體錯誤訊息。
	在 <IDList> ::= ID | <IDList> , ID 中，結合 symbol table 功能，對每個出現的 ID 進行重複性檢查，若發現相同變數名稱重複宣告，將產生錯誤提示，並持續分析後續語法。
	在賦值運算 <Assignment> ::= <LHS> = <Expression> 中，偵測是否使用了非 Java 標準賦值符號（例如 :=），若出現類 Pascal 語法，將回報不合法的賦值操作。
	在邏輯與算術運算式中，進行基本型別一致性檢查。例如：int + boolean 或 float && string 等情況，將產生型別錯誤訊息。此外，也會對非法常數格式（如 12., .34e+, 1.2.3）進行過濾。
	在條件語句 <IfStmt> ::= if ( <Expr> ) <Stmt> 與 <WhileStmt> ::= while ( <Expr> ) <Stmt> 中，檢查括號是否完整封閉，並提示漏寫右括號或語法結構不完整的情況。
	在 <MethodDecl> 中，檢查是否有缺漏的引數括號或回傳型別，並對未正確結束的 method block（例如缺少 }）提出錯誤提示。










## 遇到問題
1.	lex 把 多行comment 都視做同一行字串，對於多行 comment 要分成標示出不同不同行號需透過字串行數及陣列處理
2.	lex 把 ' ' 和 '\t' 都視做長度為一，所以針對 '\t' 計算位置會有問題，需另行處理
3.	Yacc 在做 recovery 時的訊息判別，會因為comment 在其上下列，造成行號標示錯誤，必須另行判斷
4.	可利用yacc 指令使用特殊記號名稱 error進行錯誤處理。 設計 error recovery 時，如果此位置發生輸入錯誤，剖析器會執行 ，可以快速判別文法錯誤位置，利於程式設計
















# mini java compiler

## 運行環境
Lex 版本: flex 2.6.4
Yacc 版本: bison (GNU Bison) 3.8.2
OS: ubuntu 22.04
## 執行方式
1.	Compile : 
$ make clean
$ make
2.	Execute:
$ ./myjavac <inputfile>
e.g. $ ./myjavac ./tes1.java


## 測試結果：
test1.java
![j1](https://hackmd.io/_uploads/BysqvGAUxe.png)

test2.java
 

![jj2](https://hackmd.io/_uploads/BJs2wG08le.png)


test3.java

![j3](https://hackmd.io/_uploads/SyM3vfR8lg.png)

test4.java
	 
![j4](https://hackmd.io/_uploads/Hy_pvfRLge.png)



test5.java

![jj5](https://hackmd.io/_uploads/H1yavzRLge.png)

test6.java
	 
![j66](https://hackmd.io/_uploads/HJN6wzCUge.png)


## 如何處理這份規格書上的問題
	在文法 <Program> ::= class <ClassName> { <MemberList> } 中，
定義 Java 類別的基本架構。包含：
•	class 關鍵字遺漏
•	{ 或 } 括號缺漏
•	類別主體 <MemberList> 為空時，視情況顯示提示
•	不合法的類別名稱識別字
•	漏寫分號、括號不對稱、參數遺漏、重複宣告等問題，讓語法分析器具備基礎的錯誤恢復能力。
這些錯誤會被攔截處理，印出錯誤訊息，且不會導致 parser 直接終止。


	在文法 <Declaration> ::= <Type> <IDList> ; 中，檢查變數宣告的格式是否正確，包括漏寫分號、錯用 = 或 := 賦值符號等錯誤情況，並透過語意分析階段回報具體錯誤訊息。
	在 <IDList> ::= ID | <IDList> , ID 中，結合 symbol table 功能，對每個出現的 ID 進行重複性檢查，若發現相同變數名稱重複宣告，將產生錯誤提示，並持續分析後續語法。
	在賦值運算 <Assignment> ::= <LHS> = <Expression> 中，偵測是否使用了非 Java 標準賦值符號（例如 :=），若出現類 Pascal 語法，將回報不合法的賦值操作。
	在邏輯與算術運算式中，進行基本型別一致性檢查。例如：int + boolean 或 float && string 等情況，將產生型別錯誤訊息。此外，也會對非法常數格式（如 12., .34e+, 1.2.3）進行過濾。
	在條件語句 <IfStmt> ::= if ( <Expr> ) <Stmt> 與 <WhileStmt> ::= while ( <Expr> ) <Stmt> 中，檢查括號是否完整封閉，並提示漏寫右括號或語法結構不完整的情況。
	在 <MethodDecl> 中，檢查是否有缺漏的引數括號或回傳型別，並對未正確結束的 method block（例如缺少 }）提出錯誤提示。










## 遇到問題
1.	lex 把 多行comment 都視做同一行字串，對於多行 comment 要分成標示出不同不同行號需透過字串行數及陣列處理
2.	lex 把 ' ' 和 '\t' 都視做長度為一，所以針對 '\t' 計算位置會有問題，需另行處理
3.	Yacc 在做 recovery 時的訊息判別，會因為comment 在其上下列，造成行號標示錯誤，必須另行判斷
4.	可利用yacc 指令使用特殊記號名稱 error進行錯誤處理。 設計 error recovery 時，如果此位置發生輸入錯誤，剖析器會執行 ，可以快速判別文法錯誤位置，利於程式設計
















