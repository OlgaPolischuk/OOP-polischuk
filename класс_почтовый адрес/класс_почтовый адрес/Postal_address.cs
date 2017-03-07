using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace класс_почтовый_адрес
{
    class Postal_address
    {
        public int index = 430011;
        public string city="Saransk";
        public string street = "Proletarskaya";
        public int nomber_house = 108;
        public int nomber_korp = 1;
        public int nomber_kv = 1;

        public void Edit(int choice, string new_edit)
        {
            switch (choice)
            {
                case 1:
                    index = Convert.ToInt32(new_edit);
                    break;
                case 2:
                    city = new_edit;
                    break;
                case 3:
                    street = new_edit;
                    break;
                case 4:
                    nomber_house = Convert.ToInt32(new_edit);
                    break;
                case 5:
                    nomber_korp = Convert.ToInt32(new_edit);
                    break;
                case 6:
                    nomber_kv = Convert.ToInt32(new_edit);
                    break;
            }

        }

        public void Print()
        {
            Console.WriteLine("Индекс: " + index);
            Console.WriteLine("Город: " + city);
            Console.WriteLine("Улица: " + street);
            Console.WriteLine("Номер дома: " + nomber_house);
            Console.WriteLine("Корпус: " + nomber_korp);
            Console.WriteLine("Квартира: " + nomber_kv);
            Console.WriteLine();
        }           
    }
}
