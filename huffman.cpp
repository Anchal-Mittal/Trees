
/*
S="1001011"
Processing the string from left to right.
S[0]='1' : we move to the right child of the root. We encounter a leaf node with value 'A'. We add 'A' to the decoded string.
We move back to the root.

S[1]='0' : we move to the left child. 
S[2]='0' : we move to the left child. We encounter a leaf node with value 'B'. We add 'B' to the decoded string.
We move back to the root.

S[3] = '1' : we move to the right child of the root. We encounter a leaf node with value 'A'. We add 'A' to the decoded string.
We move back to the root.

S[4]='0' : we move to the left child. 
S[5]='1' : we move to the right child. We encounter a leaf node with value C'. We add 'C' to the decoded string.
We move back to the root.

 S[6] = '1' : we move to the right child of the root. We encounter a leaf node with value 'A'. We add 'A' to the decoded string.
We move back to the root.

Decoded String = "ABACA"

*/





void decode_huff(node * root,string s)
{   node *temp=root;
    int i=0;
    int leng=s.length();
        while(i<=leng){
         if(temp->data!='\0'){
            cout << temp->data;
            temp=root;
         }
        else{
        if(s[i]=='0')
            temp=temp->left;
         else
            temp=temp->right;
         
        i++;
        }
    }
  return ;  
}
