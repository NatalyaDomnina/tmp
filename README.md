## Product Requirements Document (PRD) 

**Developer**: Natalia Domnina

**Product's type**: Сomputer program

**Product's name**: Circles

**Description**: Searching for the largest circle that does not intersect with other circles

**Platform**: Microsoft Windows 7 or higher (64-bit)

**Application type**: Console

**Input file format**: .txt file

**Сontents of input file**:

The file contains information about a set of circles. Each line is a circle. The data for each circle is separated by a comma. File template:

```
id_1,x_1,y_1,r_1
...
id_n,x_n,y_n,r_n
```
Where

* n - count of circles
* id_1 ... id_n - circle id (int)
* x_1 ... x_n - center of a circle along the x axis (double)
* y_1 ... y_n - center of a circle along the y axis (double)
* r_1 ... r_n - radius of a circle (double)

**launch type**: Using the command line

**Сommand to run**:  
```
circles.exe input_file.txt
```

Where

* circles.exe - path to program
* input_file.txt - path to input file

**Output**: List of integers, identifiers of circles, satisfying condition:

$$\mathbf{r_i} = max\left(\begin{array}
{rrr}
 r_i+r_1 > \sqrt{(x_i-x_1)^2 + (y_i-y_1)^2} \\
 ... \\
 r_i+r_n > \sqrt{(x_i-x_n)^2 + (y_i-y_n)^2}
\end{array}\right)
$$

Where 

* i - current circle, i $\in$ 1..n
* 1..n - all circles from the input file except i

If there is no solution, the output is "no circles".
