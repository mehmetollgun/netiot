//Mehmet Olgun - 2017 - NETiot
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Net;
using System.IO.Ports;

namespace Netiot
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        static string kaynakkod(string url)
        {
            HttpWebRequest reg = (HttpWebRequest)WebRequest.Create(url);
              HttpWebResponse resp = (HttpWebResponse)reg.GetResponse();
            using (StreamReader sRead = new StreamReader(resp.GetResponseStream(), Encoding.UTF8))
            {
                return sRead.ReadToEnd();
            }

        }
        SerialPort sp = new SerialPort();
        string veri;
        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                sp.PortName = "COM4";
                sp.BaudRate = 9600;
                sp.Open();
            }
            catch (Exception)
            {

                timer3.Start();
            }
          
        }
        char[] dizi = new char[32];
        private void timer1_Tick(object sender, EventArgs e)
        {
            if(sp.IsOpen)
            {
                veri = kaynakkod("http://site.com/show.php");
                char[] dizi = veri.ToCharArray();
                foreach (char eleman in dizi)
                {
                    listBox1.Items.Add(eleman);
                }
                for (int i = 0; i < listBox1.Items.Count; i++)
                {
                    sp.Write(listBox1.Items[i].ToString());
                }
               
            }
           

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (sp.IsOpen)
            {
                sp.Close();
            }
        }

        private void timer2_Tick(object sender, EventArgs e)
        {

            listBox1.Items.Clear();
            timer2.Stop();
        }

        private void timer3_Tick(object sender, EventArgs e)
        {
            try
            {
                if (!sp.IsOpen)
                {
                    sp.PortName = "COM4";
                    sp.BaudRate = 9600;
                    sp.Open();
                }
            }
            catch (Exception)
            {              
            }       
           
        }
    }
}