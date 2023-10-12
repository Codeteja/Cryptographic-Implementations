# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<stdint.h>


unsigned char S_box[256] =
{
   0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
   0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
   0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
   0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
   0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
   0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
   0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
   0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
   0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
   0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
   0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
   0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
   0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
   0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
   0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
   0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16

};


unsigned char Mul2[256] =
{
    0x00,0x02,0x04,0x06,0x08,0x0a,0x0c,0x0e,0x10,0x12,0x14,0x16,0x18,0x1a,0x1c,0x1e,
    0x20,0x22,0x24,0x26,0x28,0x2a,0x2c,0x2e,0x30,0x32,0x34,0x36,0x38,0x3a,0x3c,0x3e,
    0x40,0x42,0x44,0x46,0x48,0x4a,0x4c,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,
    0x60,0x62,0x64,0x66,0x68,0x6a,0x6c,0x6e,0x70,0x72,0x74,0x76,0x78,0x7a,0x7c,0x7e,
    0x80,0x82,0x84,0x86,0x88,0x8a,0x8c,0x8e,0x90,0x92,0x94,0x96,0x98,0x9a,0x9c,0x9e,
    0xa0,0xa2,0xa4,0xa6,0xa8,0xaa,0xac,0xae,0xb0,0xb2,0xb4,0xb6,0xb8,0xba,0xbc,0xbe,
    0xc0,0xc2,0xc4,0xc6,0xc8,0xca,0xcc,0xce,0xd0,0xd2,0xd4,0xd6,0xd8,0xda,0xdc,0xde,
    0xe0,0xe2,0xe4,0xe6,0xe8,0xea,0xec,0xee,0xf0,0xf2,0xf4,0xf6,0xf8,0xfa,0xfc,0xfe,
    0x1b,0x19,0x1f,0x1d,0x13,0x11,0x17,0x15,0x0b,0x09,0x0f,0x0d,0x03,0x01,0x07,0x05,
    0x3b,0x39,0x3f,0x3d,0x33,0x31,0x37,0x35,0x2b,0x29,0x2f,0x2d,0x23,0x21,0x27,0x25,
    0x5b,0x59,0x5f,0x5d,0x53,0x51,0x57,0x55,0x4b,0x49,0x4f,0x4d,0x43,0x41,0x47,0x45,
    0x7b,0x79,0x7f,0x7d,0x73,0x71,0x77,0x75,0x6b,0x69,0x6f,0x6d,0x63,0x61,0x67,0x65,
    0x9b,0x99,0x9f,0x9d,0x93,0x91,0x97,0x95,0x8b,0x89,0x8f,0x8d,0x83,0x81,0x87,0x85,
    0xbb,0xb9,0xbf,0xbd,0xb3,0xb1,0xb7,0xb5,0xab,0xa9,0xaf,0xad,0xa3,0xa1,0xa7,0xa5,
    0xdb,0xd9,0xdf,0xdd,0xd3,0xd1,0xd7,0xd5,0xcb,0xc9,0xcf,0xcd,0xc3,0xc1,0xc7,0xc5,
    0xfb,0xf9,0xff,0xfd,0xf3,0xf1,0xf7,0xf5,0xeb,0xe9,0xef,0xed,0xe3,0xe1,0xe7,0xe5
};

unsigned char Mul3[256] =
{
    0x00,0x03,0x06,0x05,0x0c,0x0f,0x0a,0x09,0x18,0x1b,0x1e,0x1d,0x14,0x17,0x12,0x11,
    0x30,0x33,0x36,0x35,0x3c,0x3f,0x3a,0x39,0x28,0x2b,0x2e,0x2d,0x24,0x27,0x22,0x21,
    0x60,0x63,0x66,0x65,0x6c,0x6f,0x6a,0x69,0x78,0x7b,0x7e,0x7d,0x74,0x77,0x72,0x71,
    0x50,0x53,0x56,0x55,0x5c,0x5f,0x5a,0x59,0x48,0x4b,0x4e,0x4d,0x44,0x47,0x42,0x41,
    0xc0,0xc3,0xc6,0xc5,0xcc,0xcf,0xca,0xc9,0xd8,0xdb,0xde,0xdd,0xd4,0xd7,0xd2,0xd1,
    0xf0,0xf3,0xf6,0xf5,0xfc,0xff,0xfa,0xf9,0xe8,0xeb,0xee,0xed,0xe4,0xe7,0xe2,0xe1,
    0xa0,0xa3,0xa6,0xa5,0xac,0xaf,0xaa,0xa9,0xb8,0xbb,0xbe,0xbd,0xb4,0xb7,0xb2,0xb1,
    0x90,0x93,0x96,0x95,0x9c,0x9f,0x9a,0x99,0x88,0x8b,0x8e,0x8d,0x84,0x87,0x82,0x81,
    0x9b,0x98,0x9d,0x9e,0x97,0x94,0x91,0x92,0x83,0x80,0x85,0x86,0x8f,0x8c,0x89,0x8a,
    0xab,0xa8,0xad,0xae,0xa7,0xa4,0xa1,0xa2,0xb3,0xb0,0xb5,0xb6,0xbf,0xbc,0xb9,0xba,
    0xfb,0xf8,0xfd,0xfe,0xf7,0xf4,0xf1,0xf2,0xe3,0xe0,0xe5,0xe6,0xef,0xec,0xe9,0xea,
    0xcb,0xc8,0xcd,0xce,0xc7,0xc4,0xc1,0xc2,0xd3,0xd0,0xd5,0xd6,0xdf,0xdc,0xd9,0xda,
    0x5b,0x58,0x5d,0x5e,0x57,0x54,0x51,0x52,0x43,0x40,0x45,0x46,0x4f,0x4c,0x49,0x4a,
    0x6b,0x68,0x6d,0x6e,0x67,0x64,0x61,0x62,0x73,0x70,0x75,0x76,0x7f,0x7c,0x79,0x7a,
    0x3b,0x38,0x3d,0x3e,0x37,0x34,0x31,0x32,0x23,0x20,0x25,0x26,0x2f,0x2c,0x29,0x2a,
    0x0b,0x08,0x0d,0x0e,0x07,0x04,0x01,0x02,0x13,0x10,0x15,0x16,0x1f,0x1c,0x19,0x1a
};

unsigned char Rcon[256] =
{
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
    0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
    0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
    0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
    0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
    0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
    0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
    0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
    0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
    0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
    0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
    0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
    0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
    0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
    0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
    0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d
};


void subbytes(unsigned char* state)
{
    for(int i=0 ; i<16 ; i++)
    {
        state[i] = S_box[state[i]];
    }
    /*printf("\n after Byte susbstitution \n");

    for(int i=0 ; i< 16 ; i++)
    {
        printf("%02X " , state[i]);

    }*/

}

void shifrows(unsigned char* state)
{

    unsigned char tmp[16];

    // 1st column
    tmp[0] = state[0];
    tmp[1] = state[5];
    tmp[2] = state[10];
    tmp[3] = state[15];

    // second column
    tmp[4] = state[4];
    tmp[5] = state[9];
    tmp[6] = state[14];
    tmp[7] = state[3];

    // Third column
    tmp[8] = state[8];
    tmp[9] = state[13];
    tmp[10] = state[2];
    tmp[11] = state[7];

    // fourth column
    tmp[12] = state[12];
    tmp[13] = state[1];
    tmp[14] = state[6];
    tmp[15] = state[11];

    // we will transfer this to our original state

    for(int i=0 ; i < 16 ; i++)
    {
        state[i] = tmp[i];

    }

    /*printf("\n After shift rows\n");
    for(int i=0 ; i<16 ;i++)
    {
        printf("%02X ",state[i]);

    }*/


}

void mixcolumns(unsigned char* state)
{
    unsigned char tmp[16];

    // column 1
    tmp[0] = Mul2[state[0]]^Mul3[state[1]]^state[2]^state[3];
    tmp[1] = state[0]^Mul2[state[1]]^Mul3[state[2]]^state[3];
    tmp[2] = state[0]^state[1]^Mul2[state[2]]^Mul3[state[3]];
    tmp[3] = Mul3[state[0]]^state[1]^state[2]^Mul2[state[3]];

    // column 2
    tmp[4] = Mul2[state[4]]^Mul3[state[5]]^state[6]^state[7];
    tmp[5] = state[4]^Mul2[state[5]]^Mul3[state[6]]^state[7];
    tmp[6] = state[4]^state[5]^Mul2[state[6]]^Mul3[state[7]];
    tmp[7] = Mul3[state[4]]^state[5]^state[6]^Mul2[state[7]];

    // column 3
    tmp[8] = Mul2[state[8]]^Mul3[state[9]]^state[10]^state[11];
    tmp[9] = state[8]^Mul2[state[9]]^Mul3[state[10]]^state[11];
    tmp[10] = state[8]^state[9]^Mul2[state[10]]^Mul3[state[11]];
    tmp[11] = Mul3[state[8]]^state[9]^state[10]^Mul2[state[11]];

    // column 4
    tmp[12] = Mul2[state[12]]^Mul3[state[13]]^state[14]^state[15];
    tmp[13] = state[12]^Mul2[state[13]]^Mul3[state[14]]^state[15];
    tmp[14] = state[12]^state[13]^Mul2[state[14]]^Mul3[state[15]];
    tmp[15] = Mul3[state[12]]^state[13]^state[14]^Mul2[state[15]];

    // Transfer the tmp to state

    for(int i=0 ; i<16 ; i++)
    {
        state[i] = tmp[i];
    }

    /*printf("\n After mixcolumns\n");

    for(int i=0 ; i<16 ; i++)
    {
        printf("%02X ",state[i]);

    }*/

}

void Addroundkey(unsigned char* state , unsigned char* roundkey)
{
    // adding roundkey is simply xor with the state
    for(int i=0 ; i<16 ; i++)
    {
        state[i] = state[i] ^ roundkey[i]; //mistake 1 roundKey[16] -> roundKey[i]
    }

    /*printf("\n After addition of roundkey \n");

    for(int i=0 ; i<16 ; i++)
    {
        printf("%02X ",state[i]);

    }*/


}

void keyexapnsioncore(unsigned char* in ,unsigned char i)
{
    unsigned char tmp = in[0];
    // rotation
    in[0] = in[1];
    in[1] = in[2];
    in[2] = in[3];
    in[3] = tmp;

    // byte substitution
    in[0] = S_box[in[0]];
    in[1] = S_box[in[1]];
    in[2] = S_box[in[2]];
    in[3] = S_box[in[3]];

    // Rcon addition to first byte

    in[0] = in[0] ^ Rcon[i];

    /*printf("\n  rcon work \n");

    for(int a=0 ; a<4 ; a++)
    {
        printf("%02X ",in[a]);

    }*/
}


void keyexpansion(unsigned char* inputkey , unsigned char* expandedkey)
{
    for(int i=0 ; i<16 ; i++)
    {
        expandedkey[i] = inputkey[i];
    }

    int bytesgenerated = 16;
    int rconiteration = 1;
    unsigned char tmp[4];

    while(bytesgenerated < 176)
    {
        for(int i=0 ; i<4 ; i++)
        {
            tmp[i] = expandedkey[ i + bytesgenerated - 4];
        }
        if(bytesgenerated % 16 ==0)
        {
            keyexapnsioncore(tmp ,rconiteration);
            rconiteration++;
        }
        for(int i=0 ; i<4 ; i++)
        {
            expandedkey[bytesgenerated] = expandedkey[bytesgenerated - 16]^tmp[i];
            bytesgenerated++;
        }
    }

   // printf("\n expandedkey of total 176 bits\n");
   // for(int i=0 ; i<11 ; i++)
   // {
    //    for(int j=0;j<16;j++)
       //     printf("%02X " , (i*16+expandedkey)[j]);
    //    printf("\n");

   // }
}




void aes_encrypt(unsigned char* input , unsigned char* inputkey)
{
    // Copy the input to a state varaible so we can use it to encrypt
    unsigned char state[16];
    for(int i=0 ; i< 16 ; i++)
    {
        state[i] = input[i];
    }

    printf("\n Original message \n");

    for(int i=0 ; i< 16 ; i++)
    {
        printf("%02X " ,input[i]);

    }


    unsigned char expandedkey[176]; //mistake 2 possible typo of 16 instead of 176

    keyexpansion(inputkey , expandedkey);
    //printf("/// ROUND-0 ///");

    int totalrounds = 10;
    Addroundkey(state, expandedkey);
    //printf("\n\n");
    for(int i=1 ; i<=totalrounds ; i++){
      //  printf("/// ROUND-%d ///",i);
        subbytes(state);
        shifrows(state);
        if(i!=totalrounds) mixcolumns(state);
        Addroundkey(state, expandedkey + 16 *i);
        //printf("\n\n");
    }

    printf("\nEncrypted data\n");
    for(int i=0 ; i<16 ;i++)
    {
        printf("%02X ",state[i]);
    }
}
void padding(unsigned char *plaintext, uint64_t plaintext_len, uint64_t block_size, unsigned char *block_message) {
    uint8_t j;
    uint64_t last_block_size = block_size - (plaintext_len % block_size);

    for (j = 0; j < block_size; j++) {
        if (j < last_block_size)
            block_message[j] = plaintext[j];
        else if (j == last_block_size)
            block_message[j] = 0x80;
        else
            block_message[j] = 0x00;
    }
}

// AES encryption key (128 bits)
    unsigned char encryptionKey[16] = {
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};

// Initialization Vector (IV) (128 bits)
unsigned char initializationVector[16] = {
    0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7,
    0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff
};
// Function to increment the counter portion of the IV
void incrementCounter(unsigned char *iv) {
    for (int i = 15; i >= 0; --i) {
        if (iv[i] == 0xff) {
            iv[i] = 0x00;
        } else {
            iv[i]++;
            break;
        }
    }
}

// AES-CTR encryption
void aes_ctr_encrypt(unsigned char *plaintext, int plaintext_len) {
    unsigned char counter[16];
    memcpy(counter, initializationVector, 16);

    int blockCount = (plaintext_len)/ 16; // Calculate the number of 128-bit blocks
    printf(" %d ",blockCount);
    printf("\n");
    uint64_t block_size = 16;

    // Calculate the padding length
    uint64_t padding_len = block_size - (plaintext_len % block_size);
    printf("Padding length: %lu\n", padding_len);

    // Create a buffer for the padded message
    unsigned char block_message[block_size];

    // Call the padding function with the last block of the plaintext
    padding(&plaintext[plaintext_len - (block_size - padding_len)], padding_len, block_size, block_message);
    
    printf("Padded block");
    printf("\n");
    for(int i=0 ; i<16 ; i++)
    {
        printf(" %02X ", block_message[i]);
    }
    
    printf("\n");

    for (int i = 0; i < blockCount; i++) {
        // Encrypt the counter (IV + Counter) using AES
        
        printf("Counter used for encryption is ");
        printf("\n");
        
        for(int i=0 ; i<16 ; i++)
        {
            printf(" %02X ",counter[i]);
        }
        
        aes_encrypt(counter, encryptionKey);

        // XOR the resulting block with the plaintext to produce ciphertext
        for (int j = 0; j < 16; j++) 
        {
            plaintext[i * 16 + j] ^= counter[j];
            
        }
        printf("\n");
        printf("Encryption of %d block of data is ", i+1);
        printf("\n");
        for(int i=0 ; i<16 ; i++)
        {
            printf(" %02X ",plaintext[i]);
        }

        // Increment the counter
        incrementCounter(counter);
    }
    
    printf("\n");
    printf("Counter used to encrypt padded block");
    printf("\n");
    
    for(int i=0 ; i<16 ; i++)
    {
        printf(" %02X " , counter[i]);
    }
    aes_encrypt(counter, encryptionKey);
    
    for(int i=0 ; i <16 ; i++)
    {
        block_message[i] ^= counter[i];
    }
    
    printf("\n");
    printf("Encryption of the last/padded block of the data is");
    printf("\n");
    for(int i=0 ;i<16 ; i++)
    {
        printf(" %02X ", block_message[i]);
    }
}


// AES-CTR decryption is the same as encryption
void aes_ctr_decrypt(unsigned char *ciphertext, int ciphertextLength) {
    aes_ctr_encrypt(ciphertext, ciphertextLength);
}

int main() {


    unsigned char plaintext[] = "This is a secret message";
    
    printf("Input plaintext is");
    printf("\n");
    
    int plaintext_len = strlen((char*)plaintext);
    printf(" %d " , plaintext_len);
    printf("\n");
    
    for(int i=0 ; i< plaintext_len ; i++)
    {
        printf(" %02X ", plaintext[i]);
    }

    // Encrypt the plaintext
    aes_ctr_encrypt(plaintext, strlen((char *)plaintext));

    return 0;
}
