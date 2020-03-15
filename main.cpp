#include <iostream>
#include <cstddef>

using namespace std;

struct lista
    {
        int x;
        lista *p_lista;
    };
    lista *inter=NULL;

lista *bagaen()
{
    lista *elnou=new lista;
    elnou->x=1;
    elnou->p_lista=inter;
    inter=elnou;
    return elnou;
}
void adunac(lista *elnou, int k)
{
    elnou->x=elnou->x+5*k;
    cout << elnou->x << endl;
}

lista *introduel(int key, lista *inter)
{
    lista *p_current=inter;
    if (key>=inter->x)
    {
        lista *elnou=new lista;
        elnou->x=key;
        elnou->p_lista=inter;
        inter=elnou;
        return elnou;
    }
    while (key<p_current->x && key<p_current->p_lista->x && p_current!=NULL)
        {
            p_current=p_current->p_lista;
        }
        lista *elnou=new lista;
        elnou->x=key;
        elnou->p_lista=p_current;
        p_current=elnou;
        return elnou;
}

int main()
{

    for (int i=0;i<5;i++)
        {
            adunac(bagaen(),i);
        }
        introduel(27,inter);
        while (inter!=NULL)
        {
            cout << endl << inter->x << endl << endl;
            inter=inter->p_lista;
        }
    return 0;
}
