#include <stdio.h>
#include <stdlib.h>
int main()
{
	//�û���
	char List[27] = { 0 };
	//��ĸ��
	char Alpha[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	//��Կ
	char Key[101] = { 0 };
	//����
	char Message[101] = { 0 };
	//����
	char CipherText[101] = { 0 };
	int Num = 0;
 
	//��ȡ��Կ
	printf("��������Կ: ");
	gets(Key);
 
	//�����û���
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
	//�����滻��
	int tmp;
    for(int i = 0 ; i < 13 ; i++)
    {
         tmp = List[i] ; 
         List[i] = List[25-i] ; 
         List[25-i] = tmp ;    
    }    
	//��ӡ�滻�� 
	printf("���ģ�\t");
 	for (int i = 0; i < 26; ++i)
 		{printf("| %c ",(65+i));}
	printf("\n���ģ�\t");
 	for (int i = 0; i < 26; ++i)
 		{printf("| %c ",(List[i]));}
 	printf("\n");
	//��ȡ����
	printf("����������: ");
	gets(Message);
 	
	//����
	for (int i = 0; Message[i]; ++i)
	{
		if (Message[i] == ' ')
			CipherText[i] = ' ';
		else
			if(Message[i]<91)
				CipherText[i] = List[Message[i] - 'A'];
			else 
				CipherText[i] = List[Message[i] - 'a'];
			
	}
 	
	//��ӡ����
	printf("���ܺ�����: %s\n", CipherText);
	system("PAUSE");
	return 0;
}

