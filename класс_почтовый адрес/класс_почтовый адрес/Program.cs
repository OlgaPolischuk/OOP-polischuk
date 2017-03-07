using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace класс_почтовый_адрес
{
    class Program
    {
        static void Main(string[] args)
        {
            int ch = 5;
            var obj = new Postal_address();

            while (ch != 0)
            {
                Console.WriteLine("1. Изменить адрес.");
                Console.WriteLine("2. Вывести адрес.");
                Console.WriteLine("0. Выход.");
                Console.WriteLine();
                ch = Convert.ToInt32(Console.ReadLine());

                if (ch == 1)
                {
                    int choice;
                    string new_edit = "";

                    Console.WriteLine("Изменить: ");
                    Console.WriteLine("1. Индекс.");
                    Console.WriteLine("2. Город.");
                    Console.WriteLine("3. Улицу.");
                    Console.WriteLine("4. Номер дома.");
                    Console.WriteLine("5. Корпус.");
                    Console.WriteLine("6. Квартирy.");
                    choice = Convert.ToInt32(Console.ReadLine());

                    switch (choice)
                    {
                        case 1:
                            Console.WriteLine("Ведите новое значение поля: ");
                            new_edit = Console.ReadLine();
                            break;
                        case 2:
                            Console.WriteLine("Ведите новое значение поля: ");
                            new_edit = Console.ReadLine();
                            break;
                        case 3:
                            Console.WriteLine("Ведите новое значение поля: ");
                            new_edit = Console.ReadLine();
                            break;
                        case 4:
                            Console.WriteLine("Ведите новое значение поля: ");
                            new_edit = Console.ReadLine();
                            break;
                        case 5:
                            Console.WriteLine("Ведите новое значение поля: ");
                            new_edit = Console.ReadLine();
                            break;
                        case 6:
                            Console.WriteLine("Ведите новое значение поля: ");
                            new_edit = Console.ReadLine();
                            break;
                    }

                    obj.Edit(choice, new_edit);
                    Console.Clear();
                }
                else if (ch == 2)
                {
                    obj.Print();
                }
            }
        }
    }
}