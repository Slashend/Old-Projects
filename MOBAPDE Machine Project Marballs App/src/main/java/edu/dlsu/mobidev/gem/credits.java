package edu.dlsu.mobidev.gem;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.StaggeredGridLayoutManager;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.ArrayList;

public class credits extends AppCompatActivity {

    Button home;
    RecyclerView recyclerView;
    CreditAdapter creditAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_credits);

        home = findViewById(R.id.button4Custom);

        recyclerView = (RecyclerView) findViewById(R.id.credits_recyclerview);

        ArrayList<Credit> credits = new ArrayList<>();
        credits.add(new Credit("MMBN4 Battle Pressure", "https://www.youtube.com/watch?v=33CR9ab8RCs, intellectual property of CAPCOM"));
        credits.add(new Credit("Jet Set Run", "https://www.youtube.com/watch?v=sY2B7W-T3m8, intellectual property of Yuki Hayashi"));
        credits.add(new Credit("Battle Song", "A Cyborg Fights - One Punch Man Original Soundtrack/OST"));
        credits.add(new Credit("Results, high score", "https://www.youtube.com/watch?v=sY2B7W-T3m8, intellectual property of Yuki Hayashi"));
        credits.add(new Credit("Battlefield", "https://www.youtube.com/watch?v=sY2B7W-T3m8, intellectual property of Yuki Hayashi"));
        credits.add(new Credit("Customization", "https://www.youtube.com/watch?v=sY2B7W-T3m8, intellectual property of Yuki Hayashi"));
        credits.add(new Credit("Inner circle for customization", "https://www.vectorstock.com/royalty-free-vector/futuristic-background-vector-735921"));
        credits.add(new Credit("Main menu background", "https://d2v9y0dukr6mq2.cloudfront.net/video/thumbnail/JrbItQz/blue-futuristic-title-plate-loopable-background_nyfcp80fe__F0000.png"));
        credits.add(new Credit("Setting gears", "https://www.flaticon.com/free-icon/settings_179669#term=settings&page=2&position=89"));
        credits.add(new Credit("Trophy", "https://www.flaticon.com/free-icon/trophy_337271"));
        credits.add(new Credit("Main Screen energy ball", "http://ak5.picdn.net/shutterstock/videos/14882485/thumb/5.jpg"));
        credits.add(new Credit("Main Screen Marballs font", "https://www.fotor.com/"));

        creditAdapter = new CreditAdapter(credits);

        recyclerView.setAdapter(creditAdapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(getBaseContext()));

        home.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(v.getContext(), MainMenuActivity.class);
                startActivity(i);
                finish();
            }
        });

    }
}
