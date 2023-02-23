using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Security.Cryptography.Xml;

namespace FirstFormApp
{
    public partial class Form6 : Form
    {
        [DllImport("gdi32.dll")]
        private static extern IntPtr CreateRoundRectRgn(int x1, int y1, int x2, int y2, int cx, int cy);
        [DllImport("user32.dll")]
        private static extern int SetWindowRgn(IntPtr hWnd, IntPtr hRgn, bool bRedraw);

        public Form6()
        {
            InitializeComponent();
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnC_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
            textBox2.Clear();
        }

        private void btnBack_Click(object sender, EventArgs e)
        {
            if(textBox1.Text.Length> 0)
            {
                string text = textBox1.Text;
                textBox1.Text =text.Substring(0, text.Length - 1); // 맨 오른쪽 하나를 짤라서 string 한다 즉 하나를 제거한다
            }
        }

        private void btnPlus_Click(object sender, EventArgs e)
        {
            textBox1.Text += "+"; // 컴퓨터로 계산하기 때문에 연산자와 피연산자를 기입하면 연산한다.
        }

        private void btnone_Click(object sender, EventArgs e)
        {
            textBox1.Text += "1";
        }

        private void btntwo_Click(object sender, EventArgs e)
        {
            textBox1.Text += "2";
        }

        private void btnthree_Click(object sender, EventArgs e)
        {
            textBox1.Text += "3";
        }

        private void btnfour_Click(object sender, EventArgs e)
        {
            textBox1.Text += "4";
        }

        private void btnfive_Click(object sender, EventArgs e)
        {
            textBox1.Text += "5";
        }

        private void btnsix_Click(object sender, EventArgs e)
        {
            textBox1.Text += "6";
        }

        private void btnseven_Click(object sender, EventArgs e)
        {
            textBox1.Text += "7";
        }

        private void btneight_Click(object sender, EventArgs e)
        {
            textBox1.Text += "8";
        }

        private void btnnine_Click(object sender, EventArgs e)
        {
            textBox1.Text += "9";
        }

        private void btnMinus_Click(object sender, EventArgs e)
        {
            textBox1.Text += "-";
        }

        private void btnzero_Click(object sender, EventArgs e)
        {
            textBox1.Text += "0";
        }

        private void btnMulti_Click(object sender, EventArgs e)
        {
            textBox1.Text += "*";
        }

        private void btnDivid_Click(object sender, EventArgs e)
        {
            textBox1.Text += "/";
        }

        private void btnperiod_Click(object sender, EventArgs e)
        {
            string str = textBox1.Text.ToString(); // textBox의 길이를 str에 저장해서 
            int len = str.Length; // str의 길이를 len 으로 저장하고

            if (textBox1.Text[--len] != '.') // 길이를 빼서 textBox가 .이 아닐때 .을 찍는다.
            {
                textBox1.Text += ".";
            }
        }

        private void btnRoot_Click(object sender, EventArgs e)
        {
            try
            {
                double a = Math.Sqrt(Double.Parse(textBox1.Text));
                textBox2.Text= a.ToString();
            }
            catch // 예외처리
            {
                MessageBox.Show("연산오류입니다");
            }

        }

        private void Form6_Load(object sender, EventArgs e)
        {

        }

        private void btnequal_Click(object sender, EventArgs e)
        {
            /*string k = textBox1.Text.ToString();
            int len = k.Length;
            if (k.Contains("*"))
            {
                if(textBox1.Text[--len] == '/' && textBox1.Text[--len] == '+' && textBox1.Text[--len] == '-') 
                {
                    if (textBox1.Text[++len] == '/' && textBox1.Text[++len] == '+' && textBox1.Text[++len] == '-')
                    {
                        
                    }
                }
            }*/
            try
            {
                DataTable dt = new DataTable(); // Datatable의 compute 메서드는 지정된 식을 계산한다.
                object a = dt.Compute(textBox1.Text, ""); // textBox1.Text는 계산식, ""은 필터조건 공백
                textBox2.Text = a.ToString(); // 구해진 값을 string으로 변환하며 텍스트 박스에 넣는다.
            }
            catch
            {
                MessageBox.Show("연산오류입니다");
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            //IntPtr ip = CreateRoundRectRgn(0, 0, textBox2.Width, textBox2.Height, 15, 15);
            //int i = SetWindowRgn(textBox2.Handle, ip, true);
           
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text += "(";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text += ")";
        }
    }
}
