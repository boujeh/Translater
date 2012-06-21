#include"functions.h"

void translate(char *s) {

	CURL *handle=curl_easy_init();
	char url[2000]={'\0'};
	urlEncode(s);
	sprintf(url,"%s%s","http://rednaks.alwaysdata.net/translate/?text=",s);
	if (handle){

		curl_easy_setopt(handle,CURLOPT_URL,url);
		curl_easy_perform(handle);
		curl_easy_cleanup(handle);

	}
	//printf("le texte est :%s ",s);
	else 
		printf("erreur lors de l'initialisation de la fonction curl_easy_init()\n");
		
}

/* To be able to get The entire line, scanf cant to it very well*/
void getLine(char *stream)
{
	int i=0;
	char c;
	while((c = getchar())!='\n')
	{
		stream[i++]=c;
	}
		stream[i]='\0';
}

/*Very basic url Encoding, Only spaces are supported now
feel free to hack
*/
void urlEncode(char *str)
{
	int l = strlen(str);
	int i;
	for(i=0;i<l;i++)
	{
		if(str[i]==' ')
			str[i]='+';
	}

}
