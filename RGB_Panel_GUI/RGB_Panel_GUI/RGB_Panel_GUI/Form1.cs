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
using System.IO.Ports;
//using System.IO.Porst;


namespace RGB_Panel_GUI
{
  public partial class Form1 : Form
  {
    SerialPort mySerialPort = new SerialPort( “COM3”, 9600);
    public Form1()
    {
      InitializeComponent();
    }

  }
}
