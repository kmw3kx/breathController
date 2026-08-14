hardware.display.Fill(0);

float* table_buffer = hv->getBufferForTable(hv->getHashForString("scope"));
for (int i=0; i<128; i++)
{
    int pixel = (int) ((table_buffer[i] * -1.0f + 1.0f) * 64.0f);
    hardware.display.DrawPixel(i, pixel, true);
}

hardware.display.Update();