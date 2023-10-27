```lua

1. 
{Kamus}
i : integer
{Program}
function isSimetris (l: List) -> boolean
if not isEmpty(l) then
i traversal [0 .. (l.nEff)/2]
	if getElement(l, i) /= getElement(l, l.nEff - i) then
-> false
-> true


2. 
{Kamus}
l3 : List
{Program}
function plusTab (l1,l2: List) -> List
i traversal [0 .. l.nEff]
	getElement(l3, i) <- getElement(l1, i) + getElement(l2, i)
-> l3

3. 
{Kamus}
count : integer
{Program}
function countOccurence(l: List, x: ElType) -> integer
count <- 0
i traversal [0 .. l.nEff]
	if (getElement(l, i) == x) then
count <- count + 1 
-> count


1.
{kamus}
constant COL_CAP : integer = 100
constant ROW_CAP : integer = 100

type Eltype : integer 
type m:
	< mem: matrix[0..COL_CAP-1, 0..ROW_CAP-1] of Eltype,
	  rowEff : integer,
	  colEff : integer> 
i : integer
j : integer


procedure readMatrix (output m: Matrix)
input(m.rowEff)
input(m.colEff)
i traversal [0 .. m.colEff-1] 
	j traversal [0 .. m.rowEff-1]
		input(m.mem[i, j])
-> m

2.
{kamus}
constant COL_CAP : integer = 100
constant ROW_CAP : integer = 100

type Eltype : integer 
type m:
	< mem: matrix[0..COL_CAP-1, 0..ROW_CAP-1] of Eltype,
	  rowEff : integer,
	  colEff : integer> 
i : integer
j : integer

function isMatrixEqual(m1, m2:Matrix) -> boolean
if (m1.rowEff == m2.rowEff) then
	if (m1.colEff == m2.colEff) then
i traversal [0 .. m1.colEff-1] 
	j traversal [0 .. m1.rowEff-1]
		if (m1.mem[i, j] != m2.mem[i, j]) then
			-> false
-> true
-> false




latihan soal rekursif
1.
{kamus}

{program} 
function Fibonacci(N : integer) -> integer
if (N = 1) then 
	-> 0
else if (N = 2) then
	-> 1
else
	-> Fibonacci(N-1) + Fibonacci(N-2)


2.
{kamus}

{program}
function Segitiga(N : integer) -> integer
if (N = 1) then
	-> 1
else 
	-> N + Segitiga(N-1)
		


{kamus global}
constant CAPACITY : integer = 100
constant IDX_UNDEF : integer = -999

type ElType: integer {jenis elemen list}
type List : < contents: array [0..CAPACITY] of ElType,
		   nEff: integer >= 0 >

3. 
{kamus}
extreme : integer

{program}
function ExtremeValue(l : List, max : boolean, i : integer) -> integer
if (i = l.Neff+1) then
	-> extreme
else 
	if (i = 0) then
		extreme <- l.contents[i]
else
if ((max = true) and (l.contents[i] > extreme)) then
extreme <- l.contets	
		if ((max != true) and (l.contents[i] < extreme)) then
			extreme <- l.contets
	ExtremeValue(l, max, i+1)

4.
{kamus}

{program}
procedure isIdx (input l:List, input val: ElType, input/output i : integer, output found : boolean)
if (i = l.Neff+1) then
	found <- false
i <- IDX_UNDEF { di sini udah stop }
else if (l.contents[i] = val) then 
found <- true
else 
isIdx(l, val, i+1)

5.
{kamus}

{program} 
procedure addX(input/output l: List, input val: ElType)





function isKataEqual(kata1 : kata, kata2 : kata) -> boolean
if (kata1.length = kata2.length) then
i <- 0
while (i != kata1.length) do
	



{ menghitung pasangan ‘L’ ‘E’ dalam pita }

{ kamus }
USE mesinkar
count : integer
pre : boolean

{ program }
ctr <- 0
pre <- false
start
while (cc != MARK) do 
|	if (cc = ‘L’) then
|	|	pre <- true
|	else if (cc = ‘E’) then
|	|	if (pre) then
|	|	|	ctr <- ctr + 1
|	else 
|	|	pre <- false
|	adv
output(ctr)




type queue : <


function isFull (q : queue) -> boolean
-> (q.count = CAPACITY)


procedure enqueue(input/output q: queue, input val: ElType)
q.ElType[count] <- val
q.count <- (q.count+1)%100


procedure dequeue(input/output q: queue, output val: ElType)
val <- q.ElType[idx_head]
q.idx_head <- (q.idx_head+1)%100





STACK
Kamus umum
constant IDX_UNDEF: integer = -1
constant CAPACITY: integer = 10
type ElType: integer {elemen stack}
type Stack: < buffer: array[0..CAPACITY] of integer, 
		   idxTop: integer >


kamus
s2 : Stack
i : integer
temp : ElType
procedure copyStack(input sIn: Stack, output sOut: Stack)
i <- 0
while (i != length)do
	pop(sIn, temp)
	push(s2, temp)
	i <- i + 1
i <- 0
while (i != length) do
	pop(s2, temp)
	push(s, temp)
	i <- i + 1

	


kamus
s2 : Stack
i : integer 
temp : ElType
procedure inverseStack(input/output s: Stack)
i <- 0
while (i != length)do
	pop(s, temp)
	push(s2, temp)
	i <- i + 1
copyStack(s2, s)

kamus
s3 : Stack
temp : ElType
function mergeStack(s1, s2: Stack) -> Stack
inverseStack(s2)
copyStack(s1, s3)
while not (isEmpty(s2) do
	pop (s2, temp)
	push (s3, temp)



constant IDX_UNDEF: integer = -1

{kamus}
i : integer
ret : integer


function searchX(L: list, X:ElType) -> integer
i <- 0
ret <- IDX_UNDEF
while ((i < L.Neff) and (ret = IDX_UNDEF)) do
    if (L.Array[i] = X) then
        ret <- i
    i <- i + 1
-> ret

{kamus}
i : integer
found : boolean

function searchX(L: list, X:ElType) -> integer
i <- 0
found <- false
while ((found = false) and (L.Array[i] != ) do
    if (L.Array[i] = X) then
        found <- true
    else 
        i <- i + 1
-> i
    



function isIn(X: Eltype, S: Set) -> boolean
found <- false; i <- 0
while (not found and i != S.length) do
    if (S.buffer[i] == X) then
        found <- true
    else
        i <- i + 1
-> found





procedure avgNode(input l: list)
{kamus}
p : pointer to node


if l = NIL then
	output(“hitung rata-rata gagal, elemen dari list tidak ada”)
else
	p <- l
	sum <- 0
	cnt <- 0
    repeat
		sum <- sum + p.node
		cnt <- cnt + 1
        p <- p^.next
	until(p = NIL)
	output(“rata-rata yang didapat adalah\:” + sum/cnt)
	
function max(input l: list)
{kamus}

{algoritma}
if l = NIL then
    -> 69
else
    p <- l
    max <- p^.node
    repeat
        if p^.node > max then
            max <- p^.node
        p <- p^.next
    until (p = NIL)
    -> max

function searchPos(input l: list) -> Address
{kamus}

{algoritma}
if l = NIL then
    -> NIL
else
    p <- l
    found <- false
    while (p != NIL and not found) do
        if p^.info >= 0 then
            found <- true
        else 
            p <- p^.next
    if (found) then
        -> p
    else 
        -> NIL






















```