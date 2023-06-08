/* Practical No-3
A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. 
Find the time and space requirements of your method*/

#include <iostream>
#include <vector>

using namespace std;
class Node 
{
public:
    string name;
    vector<Node*> children; //You can access nodes in the vector like this: 
	                        //node* p_left = nodeDev.
    

    Node(string name) 
	{
        this->name = name;//this is a reserved variable name and can not 
		                 //be used for anything 
    }

    void addChild(Node* node)
	 {
        children.push_back(node);
    }
};

int main()
{
    // Create the root node
    Node* book = new Node("Book");

    // Create the chapter nodes and add them as children of the book node
    Node* chapter1 = new Node("Chapter 1");
    Node* chapter2 = new Node("Chapter 2");
    book->addChild(chapter1);
    book->addChild(chapter2);

    // Create the section nodes and add them as children of the chapter nodes
    Node* section1_1 = new Node("Section 1.1");
    Node* section1_2 = new Node("Section 1.2");
    chapter1->addChild(section1_1);
    chapter1->addChild(section1_2);

    Node* section2_1 = new Node("Section 2.1");
    Node* section2_2 = new Node("Section 2.2");
    chapter2->addChild(section2_1);
    chapter2->addChild(section2_2);

    // Create the subsection nodes and add them as children of the section nodes
    Node* subsection1_1_1 = new Node("Subsection 1.1.1");
    Node* subsection1_1_2 = new Node("Subsection 1.1.2");
    section1_1->addChild(subsection1_1_1);
    section1_1->addChild(subsection1_1_2);

    Node* subsection1_2_1 = new Node("Subsection 1.2.1");
    Node* subsection1_2_2 = new Node("Subsection 1.2.2");
    section1_2->addChild(subsection1_2_1);
    section1_2->addChild(subsection1_2_2);

    Node* subsection2_1_1 = new Node("Subsection 2.1.1");
    Node* subsection2_1_2 = new Node("Subsection 2.1.2");
    section2_1->addChild(subsection2_1_1);
    section2_1->addChild(subsection2_1_2);

    Node* subsection2_2_1 = new Node("Subsection 2.2.1");
    Node* subsection2_2_2 = new Node("Subsection 2.2.2");
    section2_2->addChild(subsection2_2_1);
    section2_2->addChild(subsection2_2_2);

    // Print the nodes
    cout << book->name << endl;
    for (Node* chapter : book->children)
	 {
        cout << "\t" << chapter->name << endl;
        for (Node* section : chapter->children)
		 {
            cout << "\t\t" << section->name << endl;
            for (Node* subsection : section->children)
		 {
               
			   cout << "\t\t\t" << subsection->name << endl;
         }
        }
    }

    return 0;
}





