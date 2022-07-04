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
//But uses extra space for queue
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
int numnodes(Treenode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numnodes(root->children[i]);
    }
    return ans;
}

//Function to print the tree
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
    /*
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
    // Called by maxSumNode /
    if(root==nullptr) return 0;
    int sum = root->data; // Calculate sumNode for root Node
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        sum += root->children[i]->data;
    return sum;
}

//Function to find the node with maximum sum(i.e,sum of the data of the node and its immediate children)
Treenode<int>* maxSumNode(Treenode<int> *root){
   // /* Given a tree, find and return the node for which sum of data of all its
    // * immideate children and the node itself is maximum. In the sum, data of node
    // * itself and data of immediate children is to be taken. 
    ///* Solution: We need to traverse all the nodes and calculate the Sum for each
    // * Node. Also, we can check if maximum Sum is greater than maximum calculated
    // * till now. Here we are using post Order Traversal but we may use any
     //* traversal technique
    if(root==nullptr) return nullptr;
    Treenode<int> *result = root; // root node
    int maxSum = sumNode(root); // Calculate sumNode for root Node
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
    {
        Treenode<int> *temp = maxSumNode(root->children[i]);
        int sum = sumNode(temp);
        if(sum > maxSum)
        {
            maxSum = sum;
            result = temp;
        }
    }
    return result;
}
*/

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
    int n=numnodes(root);
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
   
    return 0;
}
