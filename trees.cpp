//# Trees-implementation-Generic-trees-
//This consists the basic functions on Data_Structure->Generic trees. Implemented language c++

//Create a treenode class
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class Treenode{
    public:
    T data;
    vector<Treenode<T>*> children;
    Treenode(T data){
        this->data=data;
    }

    //destructor to delete the tree
    //when ever we call "delete root" in main(), then its destructor is called.
    ~Treenode() {
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};

/*
//Function to count the number of nodes
//But uses extra space for queue//And it doesnt matter in which order we travel the node for count
int no_of_nodes(Treenode<int>* &root){
    int count=0;
    queue<Treenode<int>*> pend_nodes;
    pend_nodes.push(root);

    while(pend_nodes.size()!=0){
        Treenode<int>* currTreenode=pend_nodes.front();
        pend_nodes.pop();
        count++;
        for(int i=0;i<currTreenode->children.size();i++){
            pend_nodes.push(currTreenode->children[i]);
        }
    }
    return count;
} 
*/

//Function to find the number of nodes in the tree
int no_of_nodes(Treenode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=no_of_nodes(root->children[i]);
    }
    return ans;
}

//Function to print the tree levelwise
void Printtree(Treenode<int>* root){
    //edge case
    if(root==NULL){
        return;
    }
    queue<Treenode<int>*> pend_nodes;
    pend_nodes.push(root);
    while(pend_nodes.size()!=0){
        Treenode<int>* currTreenode=pend_nodes.front();
        pend_nodes.pop();
        cout<<currTreenode->data<<":";
        for(int i=0;i<currTreenode->children.size();i++){
            cout<<currTreenode->children[i]->data<<",";
            pend_nodes.push(currTreenode->children[i]);
        }
        cout<<endl;
    }
    /*  // Basically preorder traversal
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        Printtree(root->children[i]);
    }
    */
   return;
}

//Print the tree in preorder(Root gives preference itself first and then later gives priority to children)
void printpreorder(Treenode<int>* root){
    if(root==NULL){
        return;
    }
        cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
        printpreorder(root->children[i]);
    }
    return;
}

//Print the tree in postorder(Root gives preferrence to printing of its children first)
void printpostorder(Treenode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printpostorder(root->children[i]);
    }
    cout<<root->data<<' ';
}

//Function to takeinput of tree from the user
Treenode<int>* takeinputLevelWise(){
    int rootdata;
    cout<<"Enter the root data: ";
    cin>>rootdata;
    //create a root node
    Treenode<int> *root=new Treenode<int>(rootdata);
    queue<Treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        Treenode<int> *currTreenode=pendingnodes.front();
        pendingnodes.pop();
        int no_of_children;
        cout<<"Enter the number of children of "<<currTreenode->data<<": ";
        cin>>no_of_children;
        for(int i=0;i<no_of_children;i++){
            int newchild;
            cout<<"Enter the "<<i<<" th Treenode data of"<<currTreenode->data<<": ";
            cin>>newchild;
            //create a new treenode using the newchild data
            Treenode<int> *child=new Treenode<int>(newchild);
            //make connection between the parent node(currTreenode) and the created child
            currTreenode->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}

//Function to find sum of nodes
int sumofnodes(Treenode<int>* root){
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=sumofnodes(root->children[i]);
    }
    return sum;
}

//Function to maximum of the nodes in the tree
int maxofnodes(Treenode<int>* root){
    if(root==NULL){
        return -1;
    }
    int mx=root->data;
    for(int i=0;i<root->children.size();i++){
        mx=max(mx,maxofnodes(root->children[i]));
    }
    return mx;
}

//Function to find the maximum height of the tree
int findheight(Treenode<int>* root){
    if(root==NULL){
        return 0;
    }
    int height=0;
    int mxheight=0;
    for(int i=0;i<root->children.size();i++){
        height=findheight(root->children[i]);
        mxheight=max(mxheight,height);
    }
    return 1+mxheight;
}

//Print all the nodes at depth k or level k
void printnodesatlevelk(Treenode<int>* root,int k){
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printnodesatlevelk(root->children[i],k-1);
    }
    return;
}

//Function to find the number of leaf nodes
int countleafnodes(Treenode<int>* root){
    //edge case
    if(root==NULL){
        return 0;
    }
    int count=0;
    if(root->children.size()==0){
            return 1;
        }
    for(int i=0;i<root->children.size();i++){
        count+=countleafnodes(root->children[i]);
    }
    return count;
}

/*
//Function to delete the tree using recursive delete function or 
//Better idea is to use the destructor
void deletetree(Treenode<int>* root){
    if(root==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        deletetree(root->children[i]);
    }
    delete root;
}
*/


int sumNode(Treenode<int> *root){
    //used to find the maxsum node
    if(root==NULL) return 0;
    int sum = root->data;
    for(int i=0; i<root->children.size(); i++)
        sum += root->children[i]->data;
    return sum;
}

//Function to find the node with maximum sum(i.e,sum of the data of the node and its immediate children)
Treenode<int>* maxSumNode(Treenode<int> *root){
    /* Given a tree, find and return the node for which sum of data of all its
     * immediate children and the node itself is maximum.
     * Create a function to calculate the sum of itself and the immediate children
     * Solution: We need to traverse all the nodes and calculate the Sum for each
     * Node. Check whether the sum is greater than the previous node's sum.if yes then return that node.
     * Here we are using post Order Traversal but we may use any
     * traversal technique*/
    if(root==nullptr) return nullptr; // Edge case
    Treenode<int> *ans = root;//initialize ans to the root node first 
    int maxSum = sumNode(root); // Calculate sumNode for root Node
    for(int i=0; i<root->children.size(); i++)
    {
        Treenode<int> *temp = maxSumNode(root->children[i]);
        int sum = sumNode(temp);
        if(sum > maxSum){
            maxSum = sum;
            ans = temp;
        }
    }
    return ans;
}

//Function to find the next maximum data node and return it
/*Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.
 *Return NULL if no node is present with the value greater than n.
*/
Treenode<int>* Nextlargernode(Treenode<int>* root,int n){
    //create a ans treenode and initialize it to null
    Treenode<int>* ans;
    //Do small calculation on the root node
    if(root->data>n){
        ans=root;
    }
    else
    ans=NULL;
    //Now we call recursion to take care of remaining nodes
    for(int i=0;i<root->children.size();i++){
        Treenode<int>* temp=Nextlargernode(root->children[i],n);
        if(temp==NULL){
            continue;
        }
        if(ans==NULL || ans->data > temp->data){
            ans=temp;
        }
    }
    return ans;
}

//Function to find the second largest number in the tree
/*Second Largest Element In Tree
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
*/
Treenode<int>* secondlargenode(Treenode<int>* root){
    if(root==NULL || root->children.size()==0){
        return NULL;
    }
    Treenode<int>* largest=root;
    Treenode<int>* seclargest=root->children[0];
    if(root->children[0]->data > root->data){
        largest=root->children[0];
        seclargest=root;
    }
    //using queue concept
    queue<Treenode<int>*> q;
    q.push(root);
    while(!q.empty()){
        Treenode<int>* curr=q.front();
        q.pop();
        for(int i=0;i<curr->children.size();i++){
            q.push(curr->children[i]);
            if(curr->children[i]->data > seclargest->data){
                if(curr->children[i]->data > largest->data){
                    seclargest=largest;
                    largest=curr->children[i];
                }
                else {//if(curr->children[i]->data < largest->data){
                    seclargest=curr->children[i];
                }
            }
        }
    }
    return seclargest;
}

void replaceWithDepthValueHelper_func(TreeNode<int> *root, int depth){
    /* In a given Generic Tree, replace each node with its depth value. You need
      to just update the data of each node, no need to return or print anything.
    */
    if(root==NULL) return;
    root->data = depth;
    for(int i=0; i<root->children.size(); i++)
        replaceWithDepthValueHelper_func(root->children[i],depth+1);
}

void replaceWithDepthValue(TreeNode<int>* root){
    replaceWithDepthValueHelper(root,0);
}


int main(){
    /*
    Treenode<int>* root=new Treenode<int>(1);
    Treenode<int>* node1=new Treenode<int>(2);
    Treenode<int>* node2=new Treenode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    Treenode<int> *root=takeinputLevelWise();
    Printtree(root);
    int n=no_of_nodes(root);
    cout<<n<<endl;
    //cout<<sumofnodes(root)<<endl;
    //cout<<findheight(root)<<endl;
    //printnodesatlevelk(root,3);
    cout<<countleafnodes(root)<<endl;
    //printpreorder(root);
    //cout<<endl;
    //printpostorder(root);
    Treenode<int>* msn=maxSumNode(root);
    cout<<msn->data<<endl;
    Treenode<int>* nln=Nextlargernode(root,10);
    cout<<nln->data<<endl;
    Treenode<int>* sln=secondlargenode(root);
    cout<<sln->data<<endl;
   
    return 0;
}
