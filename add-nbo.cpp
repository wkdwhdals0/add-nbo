#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc,char* argv[]){
    if (argc != 3){
        printf("2개의 인자를 넣어 주세요.\n");
        return -1;
    }
	FILE *fd1,*fd2;
    uint32_t data1, data2;
    fd1 = fopen(argv[1],"rb");
    fd2 = fopen(argv[2],"rb");
    if((fd1==NULL) || (fd2==NULL)){
        printf("파일 읽어오는데 실패했습니다.\n");
        return -1;
    }
    fread(&data1,sizeof(data1), 1,fd1);
    fread(&data2,sizeof(data1), 1,fd2);
    data1 = htonl(data1);
    data2 = htonl(data2);
    printf("%d(%x) + %d(%x) = %d(%x)\n",data1,data1,data2,data2,data1+data2,data1+data2);
    fclose(fd1);
    fclose(fd2);
    return 0;
}