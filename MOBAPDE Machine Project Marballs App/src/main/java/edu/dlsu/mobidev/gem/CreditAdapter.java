package edu.dlsu.mobidev.gem;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by user on 12/15/2017.
 */

public class CreditAdapter extends RecyclerView.Adapter<CreditAdapter.CreditHolder> {
    ArrayList<Credit> credits;

    public CreditAdapter(ArrayList<Credit> credits) {
        this.credits = credits;
    }

    public class CreditHolder extends RecyclerView.ViewHolder {
        TextView tvTitle;
        TextView tvContent;

        public CreditHolder(View itemView) {
            super(itemView);

            tvTitle = (TextView) itemView.findViewById(R.id.tv_title);
            tvContent = (TextView) itemView.findViewById(R.id.tv_content);
        }
    }

    @Override
    public CreditHolder onCreateViewHolder(ViewGroup viewGroup, int i) {
        View v = LayoutInflater.from(viewGroup.getContext())
                .inflate(R.layout.list_credits, null);

        return new CreditHolder(v);
    }

    @Override
    public void onBindViewHolder(CreditHolder creditHolder, int position) {
        // TODO: change textView's text to current credit
        Credit credit = credits.get(position);
        creditHolder.tvTitle.setText(credit.getTitle());
        creditHolder.tvContent.setText(credit.getContent());
    }

    @Override
    public int getItemCount() {
        return this.credits.size();
    }

    public void addCredit(Credit credit) {
        credits.add(credit);
        notifyItemInserted(getItemCount() - 1);
    }
}
