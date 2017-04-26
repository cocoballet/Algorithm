// given string a,b,c; return a,b,c,ab,ac,bc,abc;

void Combination(char [] s){
	if(s.length == 0){
		return;
	}
	int len = s.length;
	int n = 1<<len;
	//从1循环到2^len-1
	for(int i=0;i<n;i++){
	StringBuffer sb = new StringBuffer();
	//查看第一层循环里面的任意一种取值当中的哪一位是1[比如ab,011]， 如果是1，对应的字符就存在，打印当前组合。 
	for(int j=0;j<len;j++){
		if( (i & (1<<j)) != 0) // 对应位上为1，则输出对应的字符
			sb.append(s[j]);
	}
	System.out.print(sb + " ");
}
