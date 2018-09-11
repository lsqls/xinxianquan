#include <stdio.h>
#include <stdlib.h>
int main()
{
	//置换表
	char List[27] = { 0 };
	//字母表
	char Alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	//密钥
	char Key[101] = { 0 };
	//明文
	char Message[101] = { 0 };
	//密文
	char CipherText[101] = { 0 };
	int Num = 0;
 
	//获取密钥
	printf("请输入密钥: ");
	gets(Key);
 
	//构造置换表
	for (int i = 0; Key[i]; ++i)
	{
		if (Key[i] == ' ')
			continue;
		for (int j = 0; j < 26; ++j)
		{
			if (Alpha[j] == Key[i])
			{
				Alpha[j] = 0;
				List[Num++] = Key[i];
			}
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if (!Alpha[i])
			continue;
		List[Num++] = Alpha[i];
	}
	//倒置替换表
	int tmp;
    for(int i = 0 ; i < 13 ; i++)
    {
         tmp = List[i] ; 
         List[i] = List[25-i] ; 
         List[25-i] = tmp ;    
    }    
	//打印替换表 
	printf("明文：\t");
 	for (int i = 0; i < 26; ++i)
 		{printf("| %c ",(65+i));}
	printf("\n密文：\t");
 	for (int i = 0; i < 26; ++i)
 		{printf("| %c ",(List[i]));}
 	printf("\n");
	//获取密文
	printf("请输入密文: ");
	gets(CipherText);
 	
	//解密
	for (int i = 0; CipherText[i]; ++i)
	{
		if (CipherText[i] == ' ')
			Message[i] = ' ';
		else
			for(int j=0;j<26;j++)
			{
				if(CipherText[i]==List[j])
					{
					Message[i] = char(j+65);
					break;
					}
			 } 
			
	}
	//打印密文
	printf("解密密后明文: %s\n", Message);
	system("PAUSE");
	return 0;
}

