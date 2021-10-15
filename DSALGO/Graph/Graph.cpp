#include "MyGraph.h"

enum ECity
{
	Seoul,
	Busan,
	Incheon
};

int main()
{
	MyGraph<EGraphType::Matrix> g(3);

	g.AddEdge(ECity::Seoul, ECity::Busan);
	g.AddEdge(ECity::Busan, ECity::Seoul);
	g.AddEdge(ECity::Busan, ECity::Incheon);

	g.Print();

	MyGraph<EGraphType::List> g2(3);

	g2.AddEdge(ECity::Seoul, ECity::Incheon);
	
	g2.Print();
}