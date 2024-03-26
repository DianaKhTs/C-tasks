
//
#include <iostream>
#include <cmath>

using namespace std;
struct BinaryTreeElem
{
    int _value;
    BinaryTreeElem* _left;
    BinaryTreeElem* _right;
};
void PrintTree(BinaryTreeElem* root,int offset)
{
    if (root->_right!=nullptr)
    {
        PrintTree(root->_right,offset+1);
    }
    for (int i = 0; i < offset*2;i++)
    {
        cout << " ";
    }
    cout << root->_value << endl;
    if (root->_left!=nullptr)
    {

        PrintTree(root->_left,offset+1);
    }


}

BinaryTreeElem* FindElem(BinaryTreeElem* root, int x)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if(x == root->_value)
    {
        return root;
    }
    else if (x < root->_value)
    {
        return FindElem(root->_left,x);
    }
    else 
    {
        return FindElem(root->_right,x);
    }
}

void AddElenIntoTree(BinaryTreeElem* root, int x)
{
    int k = 1;
    BinaryTreeElem* found_elem = FindElem(root,x+k);
    cout <<endl <<  x << endl;
    while (found_elem == nullptr)
    {
        found_elem = FindElem(root,x+k);
        
        k++;
    }

    BinaryTreeElem* elem_to_add = (BinaryTreeElem*)malloc(sizeof(BinaryTreeElem));
    elem_to_add->_value = x;
    elem_to_add->_left = nullptr;
    elem_to_add->_right = nullptr;

    if (found_elem->_left!= NULL && found_elem->_left->_value >= elem_to_add->_value)
    {
        elem_to_add->_right = found_elem->_left;
        
    }
    else
    {
        elem_to_add->_left = found_elem->_left;
        
    }
    found_elem->_left = elem_to_add;
    PrintTree(root,0);

  
}
//----------------------------------------------------------------------------------

int CountTreeEl(BinaryTreeElem* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return CountTreeEl(root->_left) + CountTreeEl(root->_right)+1;
}
//------------------------------------------------------------------------------------------
int SumElTree(BinaryTreeElem* root)
{
    if (root  == nullptr)
    {
        return 0;
    }
    return SumElTree(root->_left) + SumElTree(root->_right)+root->_value;
}

double AvgTreeEl(BinaryTreeElem* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    
    return  SumElTree(root)/CountTreeEl(root);

}
//------------------------------------------------------------------------------------------
//???????????????/
int CountLevels(BinaryTreeElem* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    
    
        
    return max(CountLevels(root->_left),CountLevels(root->_right)) + 1;
    
    
    
    

}
//------------------------------------------------------------------------------------------

BinaryTreeElem* GenerateBinaryTree(int min_value, int max_value)
{
    if (min_value > max_value)
    {
        return nullptr;
    }
    BinaryTreeElem* root = (BinaryTreeElem*)malloc(sizeof(BinaryTreeElem));
    int x = rand() % (max_value - min_value + 1) + min_value;
    root->_value = x;
    root->_left = nullptr;
    root->_right = nullptr;
    BinaryTreeElem* p = root;

   
    {
        int num = rand()%4;
        //cout << num << endl;
        if (num == 0)
        {
            return root;
        }
        else if (num == 1)
        {
           p->_left = GenerateBinaryTree(min_value,x-1);

        }
        else if(num == 2)
        {
            p->_right =  GenerateBinaryTree(x,max_value);
        }
        else 
        {
            p->_left = GenerateBinaryTree(min_value,x-1);
            p->_right =  GenerateBinaryTree(x,max_value);

            /*
            BinaryTreeElem* left_elem = (BinaryTreeElem*)malloc(sizeof(BinaryTreeElem));
            left_elem->_value = count++;
            left_elem->_left = nullptr;
            left_elem->_right = nullptr;
            p->_left = left_elem ;

            BinaryTreeElem* right_elem = (BinaryTreeElem*)malloc(sizeof(BinaryTreeElem));
            right_elem->_value = count++;
            right_elem->_left = nullptr;
            right_elem->_right = nullptr;
            p->_right = right_elem ;

            int choice = rand()%2;
            if (choice == 0)
            {
                p = p->_left;
            }
            else
            {
                p = p->_right;
            }
            */
        }
    }
    //cout <<"count " << count << endl;
    return root;
    



}

int MaxTreeEl(BinaryTreeElem* root)
{

    int max_el = root->_value;
    if(root->_left!=nullptr)
    {
        int temp =  MaxTreeEl(root->_left);
        if (max_el < temp)
        {
            max_el = temp;
        }

    }
    if(root->_right!=nullptr)
    {
        int temp =  MaxTreeEl(root->_right);
        if (max_el < temp)
        {
            max_el = temp;
        }
        
    }

    return max_el;






}


int main()
{
    srand(time(0));
    BinaryTreeElem* t = GenerateBinaryTree(0,20);
    PrintTree(t,0);
    cout << endl;
    //cout << MaxTreeEl(t);
    //cout << FindElem(t,5);
    //cout << CountTreeEl(t);
    //cout << AvgTreeEl(t,0);
    //cout << CountLevels(t,0);
    //AddElenIntoTree(t,5);


}