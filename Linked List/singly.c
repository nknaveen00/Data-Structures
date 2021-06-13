#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node *next;
} *newnode, *head, *temp, *temp1;
struct node *head = NULL;


void insertfirst ();
void insertlast ();
void insertmiddle ();
void deletefirst ();
void deletelast ();
void deletemiddle ();
void display ();
void length ();

int
main ()
{
  int choice, x;

  printf ("\nSingly List operations are\n");
  while (1)
    {
      printf
	("\n 1.Insert first \n 2.Insert last \n 3.Insert middle \n 4.Delete first \n 5.Delete last \n 6.Delete middle \n 7.Display \n 8.Count \n 9.Exit");
      printf ("\nEnter your choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  insertfirst ();
	  break;
	case 2:
	  insertlast ();
	  break;
	case 3:
	  insertmiddle ();
	  break;
	case 4:
	  deletefirst ();
	  break;
	case 5:
	  deletelast ();
	  break;
	case 6:
	  deletemiddle ();
	  break;
	case 7:
	  display ();
	  break;
	case 8:
	  length ();
	  break;
	case 9:
	  exit (1);

	default:
	  printf ("\n Invalid choice\n");
	  break;

	}
    }
}

void
insertfirst ()
{
  int x;
  newnode = (struct node *) malloc (sizeof (struct node));
  printf ("\nEnter the element to insert: ");
  scanf ("%d", &x);
  if (head != NULL)
    {
      newnode->data = x;
      newnode->next = head;
      head = newnode;
      printf ("\nData inserted succesfully\n");
    }
  else
    {
      newnode->data = x;
      newnode->next = NULL;
      head = newnode;
      printf ("\nData inserted successfully\n");
    }
}

void
insertlast ()
{
  int x, i;
  newnode = (struct node *) malloc (sizeof (struct node));
  printf ("\nEnter the element to insert: ");
  scanf ("%d", &x);
  temp = head;
  if (head == NULL)
    {
      newnode->data = x;
      newnode->next = NULL;
      head = newnode;
      printf ("\nData inserted successfully\n");
    }
  else
    {
      while (temp->next != NULL)
	{
	  temp = temp->next;
	}
      newnode->data = x;
      temp->next = newnode;
      newnode->next = NULL;
      printf ("\nData inserted successfully\n");
    }
}

void
insertmiddle ()
{
  int x, i = 1, count = 0, pos;
  if (head == NULL)
    {
      printf ("\nList is empty.Insertion at middle is not possible!!!\n");
    }
  else
    {
      temp = head;
      while (temp != NULL)
	{
	  count++;
	  temp = temp->next;
	}
      printf ("Enter the data to insert: ");
      scanf ("%d", &x);
      printf ("Enter the position to insert: ");
      scanf ("%d", &pos);
      if (pos < 1 || pos > count)
	{
	  printf ("\nInvalid position\n");
	}
      else
	{
	  newnode = (struct node *) malloc (sizeof (struct node));
	  temp = head;
	  while (i < pos - 1)
	    {
	      temp = temp->next;
	      if (temp == NULL)
		break;
	      i++;
	    }
	  if (temp != NULL)
	    {
	      newnode->data = x;
	      newnode->next = temp->next;
	      temp->next = newnode;
	      printf ("\nData inserted successfully\n");
	    }
	  else
	    printf ("\nCan't insert\n");
	}
    }
}

void
deletefirst ()
{

  if (head == NULL)
    printf ("\nList is empty.Can't delete any element\n");
  else
    {
      temp = head;
      head = head->next;
      free (temp);
      printf ("\nFirst Node deleted successfully\n");
    }
}


void
deletelast ()
{
  struct node *temp1;
  temp = temp1 = head;
  if (head == NULL)
    printf ("\nList is empty.Can't delete any element\n");
  else if (head->next == NULL)
    {
      head = NULL;
      free (head);
      printf ("\nLast Node deleted\n");
    }
  else if (head != NULL)
    {
      while (temp->next != NULL)
	{
	  temp1 = temp;
	  temp = temp->next;
	}

      temp1->next = NULL;
      free (temp);
      printf ("\nLast node deleted successfully\n");
    }

}

void
deletemiddle ()
{
  int i = 1, pos, count = 0;

  if (head == NULL)
    {
      printf ("\nList is empty.Can't delete any element\n");
    }
  else if (head->next == NULL)
    {
      printf ("\nThere is one element. We can't delete it.\n");
    }
  else if (head != NULL)
    {
      temp = temp1 = head;
      while (temp != NULL)
	{
	  count++;
	  temp = temp->next;
	}
      printf ("%d", count);

      printf ("\nEnter the position to delete: ");
      scanf ("%d", &pos);
      if(pos>=1||pos<=count)
      {
	  while (i < pos)
	    {
	      temp1 = temp;
	      temp = temp->next;
	      i++;
	    }
	  printf ("The deleted element is : %d ", temp->data);
	  temp1->next = temp->next;
	  free (temp);
	  printf ("\nThe element is deleted successfully\n");
      }
	  else
        printf ("\nInvalid position\n");
    }
}

void
display ()
{
  printf ("\nThe elements in the list are \n");
  temp = head;
  if (head == NULL)
    printf ("\nList is empty\n");
  else
    {
      do
	{
	  printf ("%d\t", temp->data);
	  temp = temp->next;
	}
      while (temp != NULL);
    }
}

void
length ()
{

}
