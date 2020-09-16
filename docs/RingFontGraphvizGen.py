digraph g
{

layout=circo
rankdir =TB;


rank1 [style=invis];
rank2 [style=invis];
rank1 -> rank2 [color=invis];


rank = same;


0 [fillcolor = red style=filled]
0 -> 1;
1->2;
2->3;
3->4;
4->5;
5->6;
6->7;
7->8;
8->9;
9->10;
10->11;
11->12;
12->13;
13->14;
14->15;
15->16;
16->17;
17->18;
18->19;
19->20;
20->21;
21->22;
22->23;
23->0;
rank2->6[style=invis];

{rank=same; 2,rank2,5,12}
{rank=max; 0}
rankdir =TB;


0 [fillcolor = red style=filled]


}
